#	$NetBSD: Makefile,v 1.17 2015/04/03 23:58:19 christos Exp $

.include <bsd.own.mk>

.include "../Makefile.inc"

LIB=	ssh

.if defined(__MINIX)
SRCS=   ssh_api.c \
        ssherr.c \
        sshbuf.c \
        sshkey.c \
        sshbuf-getput-basic.c \
        sshbuf-misc.c \
        sshbuf-getput-crypto.c \
        krl.c \
        bitmap.c

SRCS+=  authfd.c authfile.c bufaux.c bufbn.c bufec.c buffer.c \
        canohost.c channels.c cipher.c cipher-aes.c cipher-aesctr.c \
        cipher-bf1.c cipher-ctr.c cipher-3des1.c cleanup.c \
        compat.c crc32.c deattack.c fatal.c hostfile.c \
        log.c match.c md-sha256.c moduli.c nchan.c packet.c opacket.c \
        readpass.c rsa.c ttymodes.c xmalloc.c addrmatch.c \
        atomicio.c key.c dispatch.c mac.c uidswap.c uuencode.c misc.c \
        monitor_fdpass.c rijndael.c ssh-dss.c ssh-ecdsa.c ssh-rsa.c dh.c \
        msg.c progressmeter.c dns.c entropy.c gss-genr.c umac.c umac128.c \
        ssh-pkcs11.c smult_curve25519_ref.c \
        poly1305.c chacha.c cipher-chachapoly.c \
        ssh-ed25519.c digest-openssl.c digest-libc.c hmac.c \
        sc25519.c ge25519.c fe25519.c ed25519.c verify.c hash.c blocks.c \
        kex.c kexdh.c kexgex.c kexecdh.c kexc25519.c \
	kexdhc.c kexgexc.c kexecdhc.c kexc25519c.c \
        kexdhs.c kexgexs.c kexecdhs.c kexc25519s.c

SRCS+=  fmt_scaled.c bcrypt_pbkdf.c blowfish.c readpassphrase.c getrrsetbyname.c
SRCS+=  explicit_bzero.c timingsafe_bcmp.c bsd-misc.c reallocarray.c strtonum.c
SRCS+=  bsd-setres_id.c openssl-compat.c bindresvport.c xcrypt.c xmmap.c realpath.c
SRCS+=  roaming_common.c roaming_serv.c

.else

SRCS=\
addrmatch.c \
atomicio.c \
authfd.c \
authfile.c \
bitmap.c \
blocks.c \
bufaux.c \
bufbn.c \
bufec.c \
buffer.c \
canohost.c \
channels.c \
cipher-3des1.c \
cipher-bf1.c \
cipher-chachapoly.c \
cipher.c \
chacha.c \
cleanup.c \
compat.c \
crc32.c \
deattack.c \
dh.c \
dispatch.c \
dns.c \
ed25519.c \
fatal.c \
fe25519.c \
ge25519.c \
hash.c \
hmac.c \
hostfile.c \
kex.c \
kexdh.c \
kexdhc.c \
kexecdh.c \
kexecdhc.c \
kexgex.c \
kexgexc.c \
key.c \
krl.c \
log.c \
mac.c \
match.c \
misc.c \
monitor_fdpass.c \
msg.c \
nchan.c \
opacket.c \
packet.c \
poly1305.c \
progressmeter.c \
readpass.c \
roaming_dummy.c \
rsa.c \
sc25519.c \
smult_curve25519_ref.c \
sshbuf-getput-basic.c \
sshbuf-misc.c \
sshbuf-getput-crypto.c \
sshbuf.c \
ssherr.c \
sshkey.c \
ssh-ed25519.c \
ssh-pkcs11.c \
ttymodes.c \
uidswap.c \
umac.c \
umac128.c \
uuencode.c \
verify.c \
xmalloc.c

SRCS+=	fmt_scaled.c bcrypt_pbkdf.c blowfish.c
SRCS+=	readpassphrase.c getpeereid.c getrrsetbyname.c
.endif

OPENSSL_SRCS=\
digest-openssl.c \
kexc25519.c \
kexc25519c.c \
kexc25519s.c \
ssh-dss.c \
ssh-ecdsa.c \
ssh-rsa.c

COPTS.monitor_fdpass.c = -Wno-stack-protector

.if WITH_OPENSSL
SRCS+=		${OPENSSL_SRCS}
.else
SRCS+=		digest-libc.c
.endif

CPPFLAGS+= -DHAVE_BLF_H

CPPFLAGS+=	-I${SSHDIST}
.PATH:		${SSHDIST}

LIBDPLIBS+=	crypto	${NETBSDSRCDIR}/crypto/external/bsd/openssl/lib/libcrypto \
		crypt	${NETBSDSRCDIR}/lib/libcrypt \
		z	${NETBSDSRCDIR}/lib/libz

.for f in dns channels hostfile ssh-pkcs11
COPTS.${f}.c+=	-Wno-pointer-sign
.endfor

# XXX
COPTS.channels.c+=	-fno-strict-aliasing

.include <bsd.lib.mk>
