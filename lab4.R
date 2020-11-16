func3 <- function(n){
tri=c(1)
for(i in 2:n){
tri=c(tri,(i*(i+1))/2)
}
return(tri)
}
func4 <- function(n,k){
nkug=c(1)
for(i in 2:n){
nkug=c(nkug,k*i*(i-1)/2+1)
}
return(nkug)
}
func5<-function(n){ 
arr=matrix(c(0), nrow=n, ncol=n) 

for (i in 1:n) { 
for (j in 1:n) { 
if (((i-1) * i / 2 + 1) + (j-1) <= (i * (i - 1) / 2 + 1) + i - 1){ 
arr[i,j] = (i * (i - 1) / 2 + 1) + j - 1} 
else{ 
arr[i,j] = 0} 
} 
}
return(arr) 
}
func7<-function(n){
arr=matrix(c(0), nrow=n, ncol=n)
arr[,1]=1
for(i in 2:n){
for(j in 2:n){
arr[i,j]=arr[i-1,j-1]+arr[i-1,j]
}
}
for(i in 1:n){
for(j in 1:n){
if(arr[i,j]==0){arr[i,j]=''}
}
}
return(arr)
}

'%^%'<-function(arr, n){
if(n==0){
	arr=-abs(row(arr)-col(arr))+1
}
if(n==1){
}
if(n==-1){
	arr=solve(arr)
}
if(n<(-1)){
	n=abs(n)
	arr=solve(arr)
	arr1=arr
	for(i in 1:(n-1)){
		arr=arr%*%arr1
	}
}
if(n>1){
	arr1=arr
	for(i in 1:(n-1)){
		arr=arr%*%arr1
	}
}
return(arr)
}

pascaltri<-function(n){
lapply(0:n, function(i) choose(i, 0:i))
}