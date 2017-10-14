#	$NetBSD: Makefile.inc,v 1.3 2014/10/19 16:30:58 christos Exp $

CPPFLAGS+=-DWITH_OPENSSL
LDADD+=	-lssh -lcrypto -lcrypt -lz
LDADD+= -Wl,-z,relro -Wl,-z,now -Wl,-z,noexecstack -fstack-protector-strong 
DPADD+=	${LIBSSH} ${LIBCRYPTO} ${LIBCRYPT} ${LIBZ}

.include "${.PARSEDIR}/../Makefile.inc"
