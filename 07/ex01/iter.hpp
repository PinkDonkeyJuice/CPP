#pragma once

template<typename S>
void	iter(S *adr, int length, void (*fn)(S &))
{
	int i = 0;

	while (i < length)
	{
		fn(adr[i]);
		i++;
	}
}
