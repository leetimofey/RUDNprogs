x=seq(3.1, 6, by=0.1)
y1=pi*x
y2=exp(x)*cos(x)
require(ggplot2)
g<-ggplot(df, aes(x))
g<-g+geom_line(aes(y=y1),colour='red')
g<-g+geom_line(aes(y=y2),colour='green')
g<-g+ylab("Y(X)")+xlab("X")
g