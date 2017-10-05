#	$NetBSD: Makefile,v 1.3 2010/11/21 19:19:21 adam Exp $

.include <bsd.own.mk>

SSHDIST?= ${NETBSDSRCDIR}/crypto/external/bsd/openssh/dist

.PATH: ${SSHDIST}
.MADE: moduli
FILESDIR=/etc/ssh
FILESDIR_moduli=/etc
FILES= ssh_config sshd_config moduli

.include <bsd.files.mk>
.include <bsd.subdir.mk>
