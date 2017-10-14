#	$NetBSD: Makefile.inc,v 1.9 2015/07/23 08:03:25 mrg Exp $

WARNS?=	4

.include <bsd.own.mk>

USE_FORT?= yes	# network client/server
WITH_OPENSSL=1

SSHDIST?= ${NETBSDSRCDIR}/crypto/external/bsd/openssh/dist

CPPFLAGS+=-I${SSHDIST}

CPPFLAGS+=-DHAVE_DLOPEN
CPPFLAGS+=-DHAVE_HEADER_AD
CPPFLAGS+=-DHAVE_STDLIB_H

.if !defined(NOPIC)
CPPFLAGS+=-DHAVE_DLOPEN
.endif
.PATH: ${SSHDIST}

.if (${USE_PAM} != "no")
CPPFLAGS+=-DUSE_PAM
.else	# USE_PAM == no
.if (${USE_SKEY} != "no")
CPPFLAGS+=-DSKEY
.endif
.endif	# USE_PAM == no

.if (${USE_KERBEROS} != "no")
CPPFLAGS+=-DGSSAPI
CPPFLAGS+=-DKRB5 -DHEIMDAL
.endif

.if (${USE_LDAP} != "no")
CPPFLAGS+=-DWITH_LDAP_PUBKEY
.endif

CPPFLAGS+=-DX11BASE=\"/usr/X11R7\"

CPPFLAGS+=-DSUPPORT_UTMP -DSUPPORT_UTMPX
.if defined(__MINIX)
CPPFLAGS+=-DWITH_SSH1 -DWITH_OPENSSL -D_OPENBSD_SOURCE
CPPFLAGS+=-g -O2 -Qunused-arguments -Wunknown-warning-option -Wall -Wpointer-arith -Wuninitialized -Wsign-compare -Wformat-security -Wsizeof-pointer-memaccess -Wno-pointer-sign -Wno-unused-result -fno-strict-aliasing -D_FORTIFY_SOURCE=2 -ftrapv -fno-builtin-memset -fstack-protector-strong -Wno-error
CPPFLAGS+=-I. -I$(srcdir)  $(PATHS) -DHAVE_CONFIG_H
.else
CPPFLAGS+=-DWITH_SSH1 -DWITH_OPENSSL -DENABLE_PKCS11 -D_OPENBSD_SOURCE
CPPFLAGS+=-DHAVE_LOGIN_CAP
CPPFLAGS+=-DLIBWRAP
.endif
