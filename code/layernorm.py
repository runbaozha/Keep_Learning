import torch
import numpy as np
import torch.nn as nn

class LayerNorm(nn.Module):
    def __init__(self, normalized_shape, eps=1e-05):
        super().__init__()
        self.gamma = nn.Parameter(torch.ones(normalized_shape))
        self.beta = nn.Parameter(torch.zeros(normalized_shape))
        self.eps = eps

    def forward(self, x):
        mean = x.mean((1,2), keepdim=True)
        std = x.std(-1, keepdim=True)
        return self.gamma*(x - mean)/(std+self.eps) + self.beta



ln = torch.nn.LayerNorm([4,5])
input = torch.randn((2,4,5))
out = ln(input)

my_layernorm = LayerNorm([4, 5])
out1 = my_layernorm(input)

a = torch.ones([2,3,4])
a_mean = a.mean((1,2))
print(a_mean.size())