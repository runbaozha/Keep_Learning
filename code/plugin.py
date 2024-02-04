import torch
import torch.nn as nn
from torch.autograd import Function

class MyGelu(Function):
	@staticmethod
	def forward(ctx, input, add_num):
		return nn.GELU()(input) + add_num

	@staticmethod
	def symbolic(g, input, add):
		return g.op("MyGelu", input, add_num_f=add)

mygelu_ = MyGelu.apply

class TwoMyGelu(nn.Module):
	def __init__(self):
		super(TwoMyGelu, self).__init__()

	def forward(self, x):
		x = mygelu_(x, 0.2)
		x = mygelu_(x, 1.5)
		return x

torch_model = TwoMyGelu()
dummy_input = torch.randn(1,3,224,224)
dummy_output = torch_model(dummy_input)
# model_trace = torch.jit.trace(torch_model, dummy_input)
torch.onnx.export(torch_model, dummy_input, "./plugin.onnx")
