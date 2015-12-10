import hashlib

ok = 1
i = 1
inp = "ckczppom"

while ok:
	res = str(i)
	coin = inp + res
	hash_object = hashlib.md5(coin)
	x = hash_object.hexdigest()
	if(x[0:6] == "000000"):
		print i
		ok = 0
	i = i + 1
