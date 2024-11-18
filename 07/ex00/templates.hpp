#pragma once

template<typename S>
void	swap(S &a, S &b)
{
	S tmp = a;
	a = b;
	b = tmp;
}

template<typename M>
M	min(M a, M b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename W>
W max(W a, W b)
{
	if (a > b)
		return a;
	return b;
}