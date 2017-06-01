SDK : 36rc
Kernel : #208 (linux4)
SoC 2.0
Board 2.0
UBOOT v55
Uboot patch  - to be applied for contiguous memory (avaiable in bin/patches)
kernel patch - linux-sh4-2.6.32.16_stm24_0204-locate-initd.patch (attached)
Flash used   - NOR


-----------------------------------
For issues, please contact
Sumit BANSAL (sumit.bansal@st.com)
-----------------------------------

-----------------
SWITCH SETTINGS:
-----------------
 *	Jumper	NOR	NAND       SPI
 *	------	---	----       ---
 *	JF2	 1-2	2-3	   2-3		FLASH_CS#
 *	JF3	 1-2	2-3	   2-3		NAND_CS#
 *	JH4-2	 ON	 ON 	   OFF		MODE[5]
 *	JH4-1	OFF	OFF	   ON		MODE[4]
 *	JH2-2	 ON	 ON	   OFF		MODE[3]
 *	JH2-1	OFF	 ON	   ON		MODE[2]

PRE-REQUISITES:
----------------
1) Compile the kernel without CONFIG_DEBUG_FS, CONFIG_DEBUG_KERNEL flags
2) Compile SDK with DEBUG=0 so that modules size could be reduced


STEPS:-
--------------
1) Compile the SDK tree as usual

2) Compile the linux kernel after applying the mentioned patch

2) Download the u-boot RPM from ftp://ftp.stlinux.com/pub/stlinux/2.3/updates/RPMS/host/

3) Extract the rpm using
   rpm2cpio <package name> | cpio -dimv

4) compile uboot using below commands
   make purge_uboot
   make uboot

5) Once uboot compilation is done in step (4), copy the u-boot_hdk7108_7108, u-boot_hdk7108_7108.bin files to target for eg to :
   /opt/linux4/STM/STLinux-2.4/devkit/sh4/target/root/sumitbn_uboot

6) Append the PATH variable with /opt/linux4/STM/STLinux-2.4/devkit/sh4/bin
   export PATH=/opt/linux4/STM/STLinux-2.4/devkit/sh4/bin:$PATH

7) Compress and make an image of kernel using below commands
   sh4-linux-objcopy -O binary vmlinux vmlinux.bin
   gzip vmlinux.bin

8) export PATH=/opt/linux4/STM/STLinux-2.4/host/bin:$PATH (so as to use mkimage command)

9) To create vmlinux.ub image
    mkimage -A sh -O linux -T kernel -C gzip -a 0x8c800000 -e 0x8c801000 -n "Linux 2.6" -d vmlinux.bin.gz vmlinux.ub

    -------------------------------------------------------------------------------------
    - In the step (9) above, take care of the addresses given it might vary with memory map being used
    - To find out the memory addresses for your configuration, execute below commands to find out
      sh4-linux-objdump -f vmlinux | grep '^start address ' | awk '{print $3}'
      sh4-linux-objdump -h vmlinux | grep .empty_zero_page | awk '{print $4}'
    -------------------------------------------------------------------------------------

10) copy the vmlinux.ub image to target, for eg
    cp vmlinux.ub /opt/linux4/STM/STLinux-2.4/devkit/sh4/target/root/sumitbn_uboot/

11) From SDK environment, execute :
    make run_uboot

12) You should be able to see HDK7108 prompt on UART (on ttyAS0)

13) set ipaddr 10.199.130.26;set netmask 255.255.255.0;set gatewayip 10.199.130.254;set serverip 10.199.88.172
14) set ethaddr 00:FA:E0:FA:EC:CC;
15) set serverdir /opt/linux4/STM/STLinux-2.4/devkit/sh4/target

16) nfs 0x90000000 $serverip:/opt/linux4/STM/STLinux-2.4/devkit/sh4/target/root/sumitbn_uboot/u-boot_hdk7108_7108.bin
17) prot off 1:0-1
18) era 1:0-1
19) cp.b 0x90000000 0xa0000000 $filesize
20) prot on 1:0-1
21) saveenv

-------------------------------------------------------------------------------------------------------------
21) Just to check, if the things done as above are working, execute below steps
    - reboot the board by unplugging the power and plugg in again
    - You should be able to see HDK7108 prompt. If yes, this means uboot binary has been flashed properly and proceed to step (22)
    - If not, please re-iterate to above steps again
-------------------------------------------------------------------------------------------------------------

22) nfs 0x90000000 $serverip:/opt/linux4/STM/STLinux-2.4/devkit/sh4/target/root/sumitbn_uboot/vmlinux.ub
23) prot off 1:2-30
24) era 1:2-30
25) cp.b 0x90000000 0xa0060000 $filesize
26) prot on 1:2-30
27) set bootcmd bootm 0xa0060000
28) setenv bootargs console=ttyAS0,115200 root=/dev/nfs nwhwconf=device:eth0,hwaddr:00:FA:E0:FA:EC:CC nfsroot=$serverip:$serverdir,rsize=4096,wsize=8192,tcp ip=10.199.130.26:::255.255.0.0:STB:eth0:off bigphysarea=4000 bpa2parts=hole_for_vid_lx:4M:0x80000000:
29) saveenv

-------------------------------------------------------------------------------------------------------------
30) Just to check, if the things done as above are working, execute below steps
    - reboot the board by unplugging the power and plugg in again
    - You should be able to see HDK7108 prompt and kernel should be booted up. 
    - If yes, this means uboot binary has been flashed properly and proceed to step (31)
    - If not, please re-iterate to above steps again
-------------------------------------------------------------------------------------------------------------

31) some changes needed in below files to proceed further (needed for ramfs image only)
    /opt/linux4/STM/STLinux-2.4/devkit/sh4/target/etc/init.d/rcSBB (as attached)
    /opt/linux4/STM/STLinux-2.4/host/share/linuxshmkimg/ramfs.txt (as attached)

32) As per ramfs.txt above, as mentioned, copy all the files mentioned in home/stapp and home/stapp/lib

32) linuxshmkimg --ramdisk=32768 --rootPath=/opt/linux4/STM/STLinux-2.4/devkit/sh4/target --script=/opt/linux4/STM/STLinux-2.4/host/share/linuxshmkimg/ramfs.txt /tmp/ramdisk.img

33) mkimage -C none -A sh -O linux -T ramdisk -a 0x8d000000 -n "ST40 Linux ramdisk" -d /tmp/ramdisk.img ramdisk.ub

34) cp ramdisk.ub /opt/linux4/STM/STLinux-2.4/devkit/sh4/target/root/sumitbn_uboot

35) nfs 0x90000000 $serverip:/opt/linux4/STM/STLinux-2.4/devkit/sh4/target/root/sumitbn_uboot/ramdisk.ub
36) prot off 1:31-150
37) era 1:31-150
38) cp.b 0x90000000 0xa0460000 $filesize
39) prot on 1:31-150
40) setenv bootargs console=ttyAS1,115200 root=/dev/ram ramdisk_size=32768 bigphysarea=4000 bpa2parts=hole_for_vid_lx:4M:0x80000000:
41) set bootcmd bootm 0xa0060000 0xa0460000
42) saveenv
43) Re-boot the board now, you should be able to boot from flash.




Trials:
--------
st40load_gdb -t 10.199.130.29:hdk7108stx7108:host,no_convertor_abort=1,active_cores=host:rt,tapmux_mux=1,dual_cpu=1,,single_bin=1,overclk=1,lmi0_size=512,lmi1_size=256,lmi_contig=1,bart_offset=2,,boardrev=2,seuc=1 -c sh4tp -b /opt/linux4/STM/STLinux-$LINUX_VERSION/devkit/sources/kernel/hdk7108_7108_32bits_uboot/vmlinux -z 0x90000000,/tmp/ramdisk.img -- console=ttyAS1,115200 root=/dev/ram ramdisk_size=32768 bigphysarea=4000 bpa2parts=hole_for_vid_lx:4M:0x80000000:
