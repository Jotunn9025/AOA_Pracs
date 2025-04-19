def Hash(str):#only works for a to j as those are 10 digits
    #you could do a rolling hash but this should be good enough for the paper
    #maam only made me show this much
    sum=0
    for i in range(len(str)):
        sum+=10**i * (ord(str[i])-65)
    return sum

def RabinKarp(string,pat):
    string=string.upper()
    pat=pat.upper()
    patlen=len(pat)
    strlen=len(string)
    pathash=hash(pat)
    for i in range(strlen-patlen+1):
        if hash(string[i:i+patlen])==pathash:
            return i#if asked to return all positions just append i to a results array
    return -1

text="abcdefghi"
pat="ghi"
print(RabinKarp(text,pat))