a=c(5, 5.6, 1, 4, -5)
a
a[1]
b=numeric(3)
b<-a[2:4]
b
d=c(a[1], a[3], a[4])
d
a0=c(a, 0)
a0
k=0
for(i in 1:length(a0)){
	if (a0[i]>0){
		k=k+1
		}
	}
dd=numeric(k)
p=1
for(i in 1:length(a0)){
	if (a0[i]>0){
		dd[p]=a0[i]
		p=p+1
		}
	}
dd
for(i in 1:5){
	print(a[i]*2)
	}
for(i in 1:3){
	print(b[i]%%3)
	}
for(i in 1:3){
	print(d[i]%/%2.4)
	}
e=3/d
e
for(i in 1:3){
	print(log(d[i]*e[i]))
	}
s=0
for(i in 1:3){
	s=s+d[i]
	}
s
length(d)
w=as.character(d)
is.character(w)
w
t(d)%*%e
for(i in 1:3){
	print(d[i]*e[i])
	}
g=c(sqrt(2), log(10))
g
k=0
for(i in 1:3){
	if (d[i]==5){
		k=k+1
		}
	}
e1=numeric(k)
p=1
for(i in 1:3){
	if (d[i]==5){
		e1[p]=e[i]
		}
	}
e1
a1=c(a[1:2], a[4:5])
a1
is.vector(d)
aa=c(a[1], a[3], a[5])
aa