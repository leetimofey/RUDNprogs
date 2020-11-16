x=seq(3, 6, by=0.1)
y1=pi*x
y2=exp(x)*cos(x)
plot(x,y1,type='l',col='red',yaxt='n',ylab='y1,y2')
grid(NA,ny=NULL,col='red',lty='dashed',lwd=0.5)
legend(4.2,14,'y1=Pi*x',density=1, bty='n',cex=1,
adj=c(0,0.5),text.col='red',plot=TRUE)
par(new=TRUE)
plot(x,y2,type='l',col='green',yaxt='n',ylab='y1,y2')
grid(NA,ny=NULL,col='green',lty='dashed',lwd=0.5)
legend(4.0,50,'y2=exp(x)*cos(x)',density=1, bty='n',cex=1,
adj=c(0,0.5),text.col='green',plot=TRUE)
