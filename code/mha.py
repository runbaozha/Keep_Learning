import torch
import torch.nn as nn
import numpy as np

class ScaledDotProductAttention(nn.Module):
    def __init__(self, scale):
        super().__init__()
        self.scale = scale
        self.softmax = nn.Softmax(dim=2)

    def forward(self, q, k , v, mask=None):
        x = torch.bmm(q, k.transpose(1,2))
        x /= self.scale
        if mask is not None:
            x = x.masked_fill(mask, -np.inf)
        x = self.softmax(x)
        x = torch.bmm(x, v)

        return x

class MultiHeadAttention(nn.Module):
    def __init__(self, n_head, d_model, d_k, d_v, d_o):
        super().__init__()
        self.n_head = n_head
        self.d_model = d_model
        self.d_k = d_k
        self.d_v = d_v
        self.d_o = d_o

        self.fc_q = nn.Linear(d_model, n_head*d_k)
        self.fc_k = nn.Linear(d_model, n_head*d_k)
        self.fc_v = nn.Linear(d_model, n_head*d_v)

        self.attention = ScaledDotProductAttention(scale=np.power(d_k, 0.5))
        self.fc_o = nn.Linear(n_head*d_v, d_o)

    def forward(self, q, k, v, mask=None):
        batch, n_q, _ = q.size()
        batch, n_k, _ = k.size()
        batch, n_v, _ = v.size()

        q = self.fc_q(q)
        k = self.fc_k(k)
        v = self.fc_v(v)
        
        q = q.view(batch, n_q, self.n_head, self.d_k).permute(2, 0, 1,3).contiguous().view(-1, n_q, self.d_k)
        k = k.view(batch, n_k, self.n_head, self.d_k).permute(2, 0, 1,3).contiguous().view(-1, n_k, self.d_k)
        v = v.view(batch, n_v, self.n_head, self.d_v).permute(2, 0, 1,3).contiguous().view(-1, n_v, self.d_v)

        if mask is not None:
            mask = mask.repeat(self.n_head, 1, 1)

        out = self.attention(q, k ,v , mask)

        out = out.view(self.n_head, batch, n_q, self.d_v).permute(1,2,0,3).contiguous().view(batch, n_q, -1)

        out = self.fc_o(out)

        return out

if __name__ == "__main__":
    batch = 2
    n_q = 1024
    n_k = 32
    n_v = 32
    d_model = 512

    q = torch.randn(batch, n_q, d_model)
    k = torch.randn(batch, n_k, d_model)
    v = torch.randn(batch, n_v, d_model)    
    mask = torch.zeros(batch, n_q, n_k).bool()

    mha = MultiHeadAttention(n_head=8, d_model=512, d_k=64, d_v=128, d_o=512)
    output = mha(q, k, v, mask=mask)


    print(output.size())
