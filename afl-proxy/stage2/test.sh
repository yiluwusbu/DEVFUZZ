#clang test.c -c -emit-llvm -o  test.bc -O0 -g

# bc=~/linux/drivers/net/ethernet/dlink/sundance.o.bc
# bc=~/linux/drivers/misc/hpilo.o.bc
# bc=~/linux/drivers/net/ethernet/realtek/r8169.o.bc
# bc=~/linux/drivers/atm/fore200e.o.bc
# bc=~/linux/drivers/atm/idt77252.o.bc
# bc=~/linux/drivers/atm/eni.o.bc
# bc=~/linux/drivers/firewire/nosy.o.bc
# bc=~/linux/drivers/tty/nozomi.o.bc
# bc=~/linux/drivers/char/.applicom.o.bc
# bc=~/linux/drivers/gpu/drm/ast/ast.o.bc
# bc=~/linux/drivers/gpu/drm/qxl/qxl.o.bc
# bc=~/linux/drivers/gpu/drm/mgag200/mgag200.o.bc
# bc=~/linux/drivers/media/pci/ivtv/ivtv.o.bc
# bc=~/linux/drivers/media/pci/pt1/earth-pt1.o.bc
# bc=~/linux/drivers/media/pci/saa7134/saa7134.o.bc
# bc=~/linux/drivers/net/can/c_can/c_can_pci.o.bc
# bc=~/linux/drivers/net/can/c_can/c_can_pci.bc
# bc=~/linux/drivers/net/can/sja1000/f81601.o.bc 
# bc=~/linux/drivers/net/can/sja1000/kvaser_pci.o.bc
# bc=~/linux/drivers/net/can/sja1000/kvaser_pci.bc
# bc=~/linux/drivers/net/can/sja1000/peak_pci.o.bc
# bc=~/linux/drivers/net/can/sja1000/plx_pci.o.bc
# bc=~/linux/drivers/net/ethernet/cadence/macb_main.o.bc
# bc=~/linux/drivers/net/fddi/skfp/skfp.o.bc
# bc=~/linux/drivers/net/wan/farsync.o.bc
# bc=~/linux/drivers/net/wan/lmc/lmc.o.bc
# bc=~/linux/drivers/net/wan/wanxl.o.bc
# bc=~/linux/drivers/net/wireless/ath/ath10k/ath10k_pci.o.bc
# bc=~/linux/drivers/net/wireless/intel/iwlwifi/iwlwifi.o.bc
# bc=~/linux/drivers/net/wireless/mediatek/mt76/mt7615/mt7615e.o.bc
# bc=~/linux/drivers/net/wireless/mediatek/mt76/mt76x0/mt76x0e.o.bc
# bc=~/linux/drivers/scsi/arcmsr/arcmsr.o.bc
# bc=~/linux/drivers/scsi/lpfc/lpfc.o.bc
# bc=~/linux/drivers/scsi/ufs/ufshcd-pci-all.o.bc
# bc=~/linux/drivers/staging/sm750fb/sm750fb.o.bc
# bc=~/linux/drivers/video/fbdev/arkfb.o.bc
# bc=~/linux/drivers/video/fbdev/aty/aty128fb.o.bc
# bc=~/linux/drivers/video/fbdev/aty/atyfb.o.bc
# bc=~/linux/drivers/video/fbdev/aty/radeonfb.o.bc
# bc=~/linux/drivers/video/fbdev/carminefb.o.bc
# bc=~/linux/drivers/video/fbdev/cirrusfb.o.bc
# bc=~/linux/drivers/video/fbdev/cyber2000fb.o.bc
# bc=~/linux/drivers/video/fbdev/gxt4500.o.bc
# bc=~/linux/drivers/video/fbdev/i740fb.o.bc
# bc=~/linux/drivers/video/fbdev/kyro/kyrofb.o.bc
# bc=~/linux/drivers/video/fbdev/matrox/i2c-matroxfb.o.bc
# bc=~/linux/drivers/video/fbdev/mb862xx/mb862xxfb.o.bc
# bc=~/linux/drivers/video/fbdev/nvidia/nvidiafb.o.bc
# bc=~/linux/drivers/video/fbdev/pm2fb.o.bc
# bc=~/linux/drivers/video/fbdev/riva/rivafb.o.bc
# bc=~/linux/drivers/video/fbdev/s3fb.o.bc
# bc=~/linux/drivers/video/fbdev/sis/sisfb.o.bc
# bc=~/linux/drivers/video/fbdev/sm712fb.o.bc
# bc=~/linux/drivers/video/fbdev/vt8623fb.o.bc
bc=~/linux/drivers/net/ethernet/amd/pcnet32.o.bc
# bc=~/linux/drivers/net/ethernet/fealnx.o.bc
bc=~/linux/drivers/net/ethernet/micrel/ksz884x.o.bc
# bc=~/linux/drivers/net/ethernet/marvell/sky2.o.bc
# bc=~/linux/drivers/net/ethernet/smsc/epic100.o.bc
# bc=~/linux/drivers/net/ethernet/google/gve/gve.o.bc 
# bc=~/linux/drivers/net/ethernet/dec/tulip/de2104x.o.bc 
bc=~/linux/drivers/net/ethernet/8390/ne2k.bc
# bc=~/linux/drivers/net/ethernet/marvell/skge.o.bc
# bc=~/linux/drivers/net/ethernet/broadcom/tg3.o.bc
bc=~/linux/drivers/net/ethernet/neterion/s2io.o.bc
# bc=~/linux/drivers/net/ethernet/ti/tlan.o.bc
# bc=~/linux/drivers/net/ethernet/sis/sis190.o.bc
# bc=~/linux/drivers/net/ethernet/neterion/vxge/vxge.o.bc
# bc=~/linux/drivers/net/ethernet/3com/3c59x.o.bc
# bc=~/linux/drivers/net/ethernet/atheros/atlx/atl1.o.bc
bc=~/linux/drivers/net/vmxnet3/vmxnet3.o.bc
bc=~/linux/drivers/net/ethernet/intel/e1000/e1000.o.bc
bc=~/linux/drivers/net/ethernet/realtek/8139too.o.bc
bc=~/linux/drivers/net/ethernet/dec/tulip/tulip.o.bc
# bc=~/linux/drivers/net/ethernet/sun/sunhme.o.bc
# bc=~/linux/drivers/net/ethernet/realtek/8139cp.o.bc

#opt \
#  -load ./build/src/libapstage2.so \
#  -passes='apstage2' \
#  -stats \
#  -disable-output \
#  <${bc} 2>&1

opt-13 \
  -load ./build/src/libapstage2.so \
  -apstage2 \
  -enable-new-pm=0 \
  -stats \
  -disable-output \
  <${bc} 2>&1

