x=c(5, 0.1, 10, 0, 5.4, NA, "abc", 4, "qwerty", NA)
is.numeric(x)
is.complex(x)
is.logical(x)
is.character(x)
is.raw(x)
for (i in 1:length(x)){
	if(is.na(x[i])){
		print(i)
		}
	}
k=0
for (i in 1:length(x)){
	if(is.na(x[i])){
		k=k+1
		}
	}
if (k==0){
	print("There are no NA in x")
	}
if (k!=0){
	xna=numeric(k)
	xx=numeric(length(x)-k)
	q=1
	p=1
	for (i in 1:length(x)){
		if(is.na(x[i])){
			xna[p]=i
			p=p+1
			}
		if(is.na(x[i])==F){
			xx[q]=x[i]
			q=q+1
			}
		}
	print(xna)
	print(xx)
	}