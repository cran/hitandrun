library(hitandrun)

n.samples <- 10

constr <- list(constr=rbind(c(-1,1,1),c(1,0,-1),c(1,1,1),-diag(3)), rhs=c(0,0,1,0,0,0), dir=c("<=", "<=", "=", "<=", "<=", "<="))
chain <- hitandrun(constr, n.samples=n.samples)
stopifnot(all.equal(chain, matrix(c(0.5, 0, 0.5), ncol=3, nrow=n.samples, byrow=TRUE)))

constr <- list(constr=rbind(c(-1,1,0),c(0,1,-1),c(1,1,1),-diag(3)), rhs=c(0,0,1,0,0,0), dir=c("=", "=", "=", "<=", "<=", "<="))
chain <- hitandrun(constr, n.samples=n.samples)
stopifnot(all.equal(chain, matrix(1/3, ncol=3, nrow=n.samples)))
