#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00101FB0
// Address: 0x101fb0 - 0x102298
void sub_00101FB0_0x101fb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00101FB0_0x101fb0");
#endif

    switch (ctx->pc) {
        case 0x101fdcu: goto label_101fdc;
        case 0x10214cu: goto label_10214c;
        default: break;
    }

    ctx->pc = 0x101fb0u;

    // 0x101fb0: 0x4842d000  cfc2.ni     $v0, $vi26
    ctx->pc = 0x101fb0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->vu0_p, sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x101fb4: 0x3e00008  jr          $ra
    ctx->pc = 0x101FB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101FB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101FB4u;
            // 0x101fb8: 0x3042ffff  andi        $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101FDCu: goto label_101fdc;
            case 0x102118u: goto label_102118;
            case 0x10214Cu: goto label_10214c;
            case 0x102280u: goto label_102280;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101FBCu;
    // 0x101fbc: 0x0  nop
    ctx->pc = 0x101fbcu;
    // NOP
    // 0x101fc0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x101fc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x101fc4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x101fc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x101fc8: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x101fc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x101fcc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x101fccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101fd0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x101fd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x101fd4: 0xc040780  jal         func_101E00
    ctx->pc = 0x101FD4u;
    SET_GPR_U32(ctx, 31, 0x101FDCu);
    ctx->pc = 0x101FD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101FD4u;
            // 0x101fd8: 0x200882d  daddu       $s1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x101E00u;
    if (runtime->hasFunction(0x101E00u)) {
        auto targetFn = runtime->lookupFunction(0x101E00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101FDCu; }
        if (ctx->pc != 0x101FDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101E00_0x101e00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101FDCu; }
        if (ctx->pc != 0x101FDCu) { return; }
    }
    ctx->pc = 0x101FDCu;
label_101fdc:
    // 0x101fdc: 0x1440004e  bnez        $v0, . + 4 + (0x4E << 2)
    ctx->pc = 0x101FDCu;
    {
        const bool branch_taken_0x101fdc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x101FE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101FDCu;
            // 0x101fe0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101fdc) {
            ctx->pc = 0x102118u;
            goto label_102118;
        }
    }
    ctx->pc = 0x101FE4u;
    // 0x101fe4: 0xfa200000  sqc2        $vf0, 0x0($s1)
    ctx->pc = 0x101fe4u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), _mm_castps_si128(ctx->vu0_vf[0]));
    // 0x101fe8: 0xfa210010  sqc2        $vf1, 0x10($s1)
    ctx->pc = 0x101fe8u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 16), _mm_castps_si128(ctx->vu0_vf[1]));
    // 0x101fec: 0xfa220020  sqc2        $vf2, 0x20($s1)
    ctx->pc = 0x101fecu;
    WRITE128(ADD32(GPR_U32(ctx, 17), 32), _mm_castps_si128(ctx->vu0_vf[2]));
    // 0x101ff0: 0xfa230030  sqc2        $vf3, 0x30($s1)
    ctx->pc = 0x101ff0u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 48), _mm_castps_si128(ctx->vu0_vf[3]));
    // 0x101ff4: 0xfa240040  sqc2        $vf4, 0x40($s1)
    ctx->pc = 0x101ff4u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 64), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x101ff8: 0xfa250050  sqc2        $vf5, 0x50($s1)
    ctx->pc = 0x101ff8u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 80), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x101ffc: 0xfa260060  sqc2        $vf6, 0x60($s1)
    ctx->pc = 0x101ffcu;
    WRITE128(ADD32(GPR_U32(ctx, 17), 96), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x102000: 0xfa270070  sqc2        $vf7, 0x70($s1)
    ctx->pc = 0x102000u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 112), _mm_castps_si128(ctx->vu0_vf[7]));
    // 0x102004: 0xfa280080  sqc2        $vf8, 0x80($s1)
    ctx->pc = 0x102004u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 128), _mm_castps_si128(ctx->vu0_vf[8]));
    // 0x102008: 0xfa290090  sqc2        $vf9, 0x90($s1)
    ctx->pc = 0x102008u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 144), _mm_castps_si128(ctx->vu0_vf[9]));
    // 0x10200c: 0xfa2a00a0  sqc2        $vf10, 0xA0($s1)
    ctx->pc = 0x10200cu;
    WRITE128(ADD32(GPR_U32(ctx, 17), 160), _mm_castps_si128(ctx->vu0_vf[10]));
    // 0x102010: 0xfa2b00b0  sqc2        $vf11, 0xB0($s1)
    ctx->pc = 0x102010u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 176), _mm_castps_si128(ctx->vu0_vf[11]));
    // 0x102014: 0xfa2c00c0  sqc2        $vf12, 0xC0($s1)
    ctx->pc = 0x102014u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 192), _mm_castps_si128(ctx->vu0_vf[12]));
    // 0x102018: 0xfa2d00d0  sqc2        $vf13, 0xD0($s1)
    ctx->pc = 0x102018u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 208), _mm_castps_si128(ctx->vu0_vf[13]));
    // 0x10201c: 0xfa2e00e0  sqc2        $vf14, 0xE0($s1)
    ctx->pc = 0x10201cu;
    WRITE128(ADD32(GPR_U32(ctx, 17), 224), _mm_castps_si128(ctx->vu0_vf[14]));
    // 0x102020: 0xfa2f00f0  sqc2        $vf15, 0xF0($s1)
    ctx->pc = 0x102020u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 240), _mm_castps_si128(ctx->vu0_vf[15]));
    // 0x102024: 0xfa300100  sqc2        $vf16, 0x100($s1)
    ctx->pc = 0x102024u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 256), _mm_castps_si128(ctx->vu0_vf[16]));
    // 0x102028: 0xfa310110  sqc2        $vf17, 0x110($s1)
    ctx->pc = 0x102028u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 272), _mm_castps_si128(ctx->vu0_vf[17]));
    // 0x10202c: 0xfa320120  sqc2        $vf18, 0x120($s1)
    ctx->pc = 0x10202cu;
    WRITE128(ADD32(GPR_U32(ctx, 17), 288), _mm_castps_si128(ctx->vu0_vf[18]));
    // 0x102030: 0xfa330130  sqc2        $vf19, 0x130($s1)
    ctx->pc = 0x102030u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 304), _mm_castps_si128(ctx->vu0_vf[19]));
    // 0x102034: 0xfa340140  sqc2        $vf20, 0x140($s1)
    ctx->pc = 0x102034u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 320), _mm_castps_si128(ctx->vu0_vf[20]));
    // 0x102038: 0xfa350150  sqc2        $vf21, 0x150($s1)
    ctx->pc = 0x102038u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 336), _mm_castps_si128(ctx->vu0_vf[21]));
    // 0x10203c: 0xfa360160  sqc2        $vf22, 0x160($s1)
    ctx->pc = 0x10203cu;
    WRITE128(ADD32(GPR_U32(ctx, 17), 352), _mm_castps_si128(ctx->vu0_vf[22]));
    // 0x102040: 0xfa370170  sqc2        $vf23, 0x170($s1)
    ctx->pc = 0x102040u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 368), _mm_castps_si128(ctx->vu0_vf[23]));
    // 0x102044: 0xfa380180  sqc2        $vf24, 0x180($s1)
    ctx->pc = 0x102044u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 384), _mm_castps_si128(ctx->vu0_vf[24]));
    // 0x102048: 0xfa390190  sqc2        $vf25, 0x190($s1)
    ctx->pc = 0x102048u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 400), _mm_castps_si128(ctx->vu0_vf[25]));
    // 0x10204c: 0xfa3a01a0  sqc2        $vf26, 0x1A0($s1)
    ctx->pc = 0x10204cu;
    WRITE128(ADD32(GPR_U32(ctx, 17), 416), _mm_castps_si128(ctx->vu0_vf[26]));
    // 0x102050: 0xfa3b01b0  sqc2        $vf27, 0x1B0($s1)
    ctx->pc = 0x102050u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 432), _mm_castps_si128(ctx->vu0_vf[27]));
    // 0x102054: 0xfa3c01c0  sqc2        $vf28, 0x1C0($s1)
    ctx->pc = 0x102054u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 448), _mm_castps_si128(ctx->vu0_vf[28]));
    // 0x102058: 0xfa3d01d0  sqc2        $vf29, 0x1D0($s1)
    ctx->pc = 0x102058u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 464), _mm_castps_si128(ctx->vu0_vf[29]));
    // 0x10205c: 0xfa3e01e0  sqc2        $vf30, 0x1E0($s1)
    ctx->pc = 0x10205cu;
    WRITE128(ADD32(GPR_U32(ctx, 17), 480), _mm_castps_si128(ctx->vu0_vf[30]));
    // 0x102060: 0xfa3f01f0  sqc2        $vf31, 0x1F0($s1)
    ctx->pc = 0x102060u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 496), _mm_castps_si128(ctx->vu0_vf[31]));
    // 0x102064: 0x48428000  cfc2.ni     $v0, $vi16
    ctx->pc = 0x102064u;
    SET_GPR_U32(ctx, 2, ctx->vu0_vpu_stat4);
    // 0x102068: 0xae020200  sw          $v0, 0x200($s0)
    ctx->pc = 0x102068u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 512), GPR_U32(ctx, 2));
    // 0x10206c: 0x48428800  cfc2.ni     $v0, $vi17
    ctx->pc = 0x10206cu;
    SET_GPR_U32(ctx, 2, ctx->vu0_cmsar3);
    // 0x102070: 0xae020204  sw          $v0, 0x204($s0)
    ctx->pc = 0x102070u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 516), GPR_U32(ctx, 2));
    // 0x102074: 0x48429000  cfc2.ni     $v0, $vi18
    ctx->pc = 0x102074u;
    SET_GPR_U32(ctx, 2, ctx->vu0_fbrst4);
    // 0x102078: 0xae020208  sw          $v0, 0x208($s0)
    ctx->pc = 0x102078u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 520), GPR_U32(ctx, 2));
    // 0x10207c: 0x4842a000  cfc2.ni     $v0, $vi20
    ctx->pc = 0x10207cu;
    SET_GPR_VEC(ctx, 2, _mm_castps_si128(ctx->vu0_acc));
    // 0x102080: 0xae02020c  sw          $v0, 0x20C($s0)
    ctx->pc = 0x102080u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 524), GPR_U32(ctx, 2));
    // 0x102084: 0x4842a800  cfc2.ni     $v0, $vi21
    ctx->pc = 0x102084u;
    SET_GPR_U32(ctx, 2, ctx->vu0_info);
    // 0x102088: 0xae020210  sw          $v0, 0x210($s0)
    ctx->pc = 0x102088u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 528), GPR_U32(ctx, 2));
    // 0x10208c: 0x4842b000  cfc2.ni     $v0, $vi22
    ctx->pc = 0x10208cu;
    SET_GPR_U32(ctx, 2, ctx->vu0_clip_flags2);
    // 0x102090: 0xae020214  sw          $v0, 0x214($s0)
    ctx->pc = 0x102090u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 532), GPR_U32(ctx, 2));
    // 0x102094: 0x48420000  cfc2.ni     $v0, $vi0
    ctx->pc = 0x102094u;
    SET_GPR_U32(ctx, 2, ctx->vu0_status);
    // 0x102098: 0xa6020218  sh          $v0, 0x218($s0)
    ctx->pc = 0x102098u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 536), (uint16_t)GPR_U32(ctx, 2));
    // 0x10209c: 0x48420800  cfc2.ni     $v0, $vi1
    ctx->pc = 0x10209cu;
    SET_GPR_U32(ctx, 2, ctx->vu0_mac_flags);
    // 0x1020a0: 0xa602021a  sh          $v0, 0x21A($s0)
    ctx->pc = 0x1020a0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 538), (uint16_t)GPR_U32(ctx, 2));
    // 0x1020a4: 0x48421000  cfc2.ni     $v0, $vi2
    ctx->pc = 0x1020a4u;
    SET_GPR_U32(ctx, 2, ctx->vu0_vpu_stat);
    // 0x1020a8: 0xa602021c  sh          $v0, 0x21C($s0)
    ctx->pc = 0x1020a8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 540), (uint16_t)GPR_U32(ctx, 2));
    // 0x1020ac: 0x48421800  cfc2.ni     $v0, $vi3
    ctx->pc = 0x1020acu;
    SET_GPR_VEC(ctx, 2, _mm_castps_si128(ctx->vu0_r));
    // 0x1020b0: 0xa602021e  sh          $v0, 0x21E($s0)
    ctx->pc = 0x1020b0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 542), (uint16_t)GPR_U32(ctx, 2));
    // 0x1020b4: 0x48422000  cfc2.ni     $v0, $vi4
    ctx->pc = 0x1020b4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->vu0_i, sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x1020b8: 0xa6020220  sh          $v0, 0x220($s0)
    ctx->pc = 0x1020b8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 544), (uint16_t)GPR_U32(ctx, 2));
    // 0x1020bc: 0x48422800  cfc2.ni     $v0, $vi5
    ctx->pc = 0x1020bcu;
    SET_GPR_U32(ctx, 2, ctx->vu0_clip_flags);
    // 0x1020c0: 0xa6020222  sh          $v0, 0x222($s0)
    ctx->pc = 0x1020c0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 546), (uint16_t)GPR_U32(ctx, 2));
    // 0x1020c4: 0x48423000  cfc2.ni     $v0, $vi6
    ctx->pc = 0x1020c4u;
    SET_GPR_U32(ctx, 2, ctx->vu0_tpc);
    // 0x1020c8: 0xa6020224  sh          $v0, 0x224($s0)
    ctx->pc = 0x1020c8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 548), (uint16_t)GPR_U32(ctx, 2));
    // 0x1020cc: 0x48423800  cfc2.ni     $v0, $vi7
    ctx->pc = 0x1020ccu;
    SET_GPR_U32(ctx, 2, ctx->vu0_cmsar0);
    // 0x1020d0: 0xa6020226  sh          $v0, 0x226($s0)
    ctx->pc = 0x1020d0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 550), (uint16_t)GPR_U32(ctx, 2));
    // 0x1020d4: 0x48424000  cfc2.ni     $v0, $vi8
    ctx->pc = 0x1020d4u;
    SET_GPR_U32(ctx, 2, ctx->vu0_fbrst);
    // 0x1020d8: 0xa6020228  sh          $v0, 0x228($s0)
    ctx->pc = 0x1020d8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 552), (uint16_t)GPR_U32(ctx, 2));
    // 0x1020dc: 0x48424800  cfc2.ni     $v0, $vi9
    ctx->pc = 0x1020dcu;
    SET_GPR_U32(ctx, 2, ctx->vu0_vpu_stat2);
    // 0x1020e0: 0xa602022a  sh          $v0, 0x22A($s0)
    ctx->pc = 0x1020e0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 554), (uint16_t)GPR_U32(ctx, 2));
    // 0x1020e4: 0x48425000  cfc2.ni     $v0, $vi10
    ctx->pc = 0x1020e4u;
    SET_GPR_U32(ctx, 2, ctx->vu0_tpc2);
    // 0x1020e8: 0xa602022c  sh          $v0, 0x22C($s0)
    ctx->pc = 0x1020e8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 556), (uint16_t)GPR_U32(ctx, 2));
    // 0x1020ec: 0x48425800  cfc2.ni     $v0, $vi11
    ctx->pc = 0x1020ecu;
    SET_GPR_U32(ctx, 2, ctx->vu0_cmsar1);
    // 0x1020f0: 0xa602022e  sh          $v0, 0x22E($s0)
    ctx->pc = 0x1020f0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 558), (uint16_t)GPR_U32(ctx, 2));
    // 0x1020f4: 0x48426000  cfc2.ni     $v0, $vi12
    ctx->pc = 0x1020f4u;
    SET_GPR_U32(ctx, 2, ctx->vu0_fbrst2);
    // 0x1020f8: 0xa6020230  sh          $v0, 0x230($s0)
    ctx->pc = 0x1020f8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 560), (uint16_t)GPR_U32(ctx, 2));
    // 0x1020fc: 0x48426800  cfc2.ni     $v0, $vi13
    ctx->pc = 0x1020fcu;
    SET_GPR_U32(ctx, 2, ctx->vu0_vpu_stat3);
    // 0x102100: 0xa6020232  sh          $v0, 0x232($s0)
    ctx->pc = 0x102100u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 562), (uint16_t)GPR_U32(ctx, 2));
    // 0x102104: 0x48427000  cfc2.ni     $v0, $vi14
    ctx->pc = 0x102104u;
    SET_GPR_U32(ctx, 2, ctx->vu0_cmsar2);
    // 0x102108: 0xa6020234  sh          $v0, 0x234($s0)
    ctx->pc = 0x102108u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 564), (uint16_t)GPR_U32(ctx, 2));
    // 0x10210c: 0x48427800  cfc2.ni     $v0, $vi15
    ctx->pc = 0x10210cu;
    SET_GPR_U32(ctx, 2, ctx->vu0_fbrst3);
    // 0x102110: 0xa6020236  sh          $v0, 0x236($s0)
    ctx->pc = 0x102110u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 566), (uint16_t)GPR_U32(ctx, 2));
    // 0x102114: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x102114u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_102118:
    // 0x102118: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x102118u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10211c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x10211cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x102120: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x102120u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x102124: 0x3e00008  jr          $ra
    ctx->pc = 0x102124u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102124u;
            // 0x102128: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101FDCu: goto label_101fdc;
            case 0x102118u: goto label_102118;
            case 0x10214Cu: goto label_10214c;
            case 0x102280u: goto label_102280;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10212Cu;
    // 0x10212c: 0x0  nop
    ctx->pc = 0x10212cu;
    // NOP
    // 0x102130: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x102130u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x102134: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x102134u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x102138: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x102138u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x10213c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x10213cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102140: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x102140u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x102144: 0xc040780  jal         func_101E00
    ctx->pc = 0x102144u;
    SET_GPR_U32(ctx, 31, 0x10214Cu);
    ctx->pc = 0x102148u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102144u;
            // 0x102148: 0x200882d  daddu       $s1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x101E00u;
    if (runtime->hasFunction(0x101E00u)) {
        auto targetFn = runtime->lookupFunction(0x101E00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10214Cu; }
        if (ctx->pc != 0x10214Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101E00_0x101e00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10214Cu; }
        if (ctx->pc != 0x10214Cu) { return; }
    }
    ctx->pc = 0x10214Cu;
label_10214c:
    // 0x10214c: 0x1440004c  bnez        $v0, . + 4 + (0x4C << 2)
    ctx->pc = 0x10214Cu;
    {
        const bool branch_taken_0x10214c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x102150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10214Cu;
            // 0x102150: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10214c) {
            ctx->pc = 0x102280u;
            goto label_102280;
        }
    }
    ctx->pc = 0x102154u;
    // 0x102154: 0xda200000  lqc2        $vf0, 0x0($s1)
    ctx->pc = 0x102154u;
    ctx->vu0_vf[0] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x102158: 0xda210010  lqc2        $vf1, 0x10($s1)
    ctx->pc = 0x102158u;
    ctx->vu0_vf[1] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x10215c: 0xda220020  lqc2        $vf2, 0x20($s1)
    ctx->pc = 0x10215cu;
    ctx->vu0_vf[2] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x102160: 0xda230030  lqc2        $vf3, 0x30($s1)
    ctx->pc = 0x102160u;
    ctx->vu0_vf[3] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 48)));
    // 0x102164: 0xda240040  lqc2        $vf4, 0x40($s1)
    ctx->pc = 0x102164u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 64)));
    // 0x102168: 0xda250050  lqc2        $vf5, 0x50($s1)
    ctx->pc = 0x102168u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 80)));
    // 0x10216c: 0xda260060  lqc2        $vf6, 0x60($s1)
    ctx->pc = 0x10216cu;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 96)));
    // 0x102170: 0xda270070  lqc2        $vf7, 0x70($s1)
    ctx->pc = 0x102170u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 112)));
    // 0x102174: 0xda280080  lqc2        $vf8, 0x80($s1)
    ctx->pc = 0x102174u;
    ctx->vu0_vf[8] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 128)));
    // 0x102178: 0xda290090  lqc2        $vf9, 0x90($s1)
    ctx->pc = 0x102178u;
    ctx->vu0_vf[9] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 144)));
    // 0x10217c: 0xda2a00a0  lqc2        $vf10, 0xA0($s1)
    ctx->pc = 0x10217cu;
    ctx->vu0_vf[10] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 160)));
    // 0x102180: 0xda2b00b0  lqc2        $vf11, 0xB0($s1)
    ctx->pc = 0x102180u;
    ctx->vu0_vf[11] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 176)));
    // 0x102184: 0xda2c00c0  lqc2        $vf12, 0xC0($s1)
    ctx->pc = 0x102184u;
    ctx->vu0_vf[12] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 192)));
    // 0x102188: 0xda2d00d0  lqc2        $vf13, 0xD0($s1)
    ctx->pc = 0x102188u;
    ctx->vu0_vf[13] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 208)));
    // 0x10218c: 0xda2e00e0  lqc2        $vf14, 0xE0($s1)
    ctx->pc = 0x10218cu;
    ctx->vu0_vf[14] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 224)));
    // 0x102190: 0xda2f00f0  lqc2        $vf15, 0xF0($s1)
    ctx->pc = 0x102190u;
    ctx->vu0_vf[15] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 240)));
    // 0x102194: 0xda300100  lqc2        $vf16, 0x100($s1)
    ctx->pc = 0x102194u;
    ctx->vu0_vf[16] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 256)));
    // 0x102198: 0xda310110  lqc2        $vf17, 0x110($s1)
    ctx->pc = 0x102198u;
    ctx->vu0_vf[17] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 272)));
    // 0x10219c: 0xda320120  lqc2        $vf18, 0x120($s1)
    ctx->pc = 0x10219cu;
    ctx->vu0_vf[18] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 288)));
    // 0x1021a0: 0xda330130  lqc2        $vf19, 0x130($s1)
    ctx->pc = 0x1021a0u;
    ctx->vu0_vf[19] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 304)));
    // 0x1021a4: 0xda340140  lqc2        $vf20, 0x140($s1)
    ctx->pc = 0x1021a4u;
    ctx->vu0_vf[20] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 320)));
    // 0x1021a8: 0xda350150  lqc2        $vf21, 0x150($s1)
    ctx->pc = 0x1021a8u;
    ctx->vu0_vf[21] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 336)));
    // 0x1021ac: 0xda360160  lqc2        $vf22, 0x160($s1)
    ctx->pc = 0x1021acu;
    ctx->vu0_vf[22] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 352)));
    // 0x1021b0: 0xda370170  lqc2        $vf23, 0x170($s1)
    ctx->pc = 0x1021b0u;
    ctx->vu0_vf[23] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 368)));
    // 0x1021b4: 0xda380180  lqc2        $vf24, 0x180($s1)
    ctx->pc = 0x1021b4u;
    ctx->vu0_vf[24] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 384)));
    // 0x1021b8: 0xda390190  lqc2        $vf25, 0x190($s1)
    ctx->pc = 0x1021b8u;
    ctx->vu0_vf[25] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 400)));
    // 0x1021bc: 0xda3a01a0  lqc2        $vf26, 0x1A0($s1)
    ctx->pc = 0x1021bcu;
    ctx->vu0_vf[26] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 416)));
    // 0x1021c0: 0xda3b01b0  lqc2        $vf27, 0x1B0($s1)
    ctx->pc = 0x1021c0u;
    ctx->vu0_vf[27] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 432)));
    // 0x1021c4: 0xda3c01c0  lqc2        $vf28, 0x1C0($s1)
    ctx->pc = 0x1021c4u;
    ctx->vu0_vf[28] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 448)));
    // 0x1021c8: 0xda3d01d0  lqc2        $vf29, 0x1D0($s1)
    ctx->pc = 0x1021c8u;
    ctx->vu0_vf[29] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 464)));
    // 0x1021cc: 0xda3e01e0  lqc2        $vf30, 0x1E0($s1)
    ctx->pc = 0x1021ccu;
    ctx->vu0_vf[30] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 480)));
    // 0x1021d0: 0xda3f01f0  lqc2        $vf31, 0x1F0($s1)
    ctx->pc = 0x1021d0u;
    ctx->vu0_vf[31] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 496)));
    // 0x1021d4: 0x8e020200  lw          $v0, 0x200($s0)
    ctx->pc = 0x1021d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 512)));
    // 0x1021d8: 0x48c28000  ctc2.ni     $v0, $vi16
    ctx->pc = 0x1021d8u;
    ctx->vu0_vpu_stat4 = GPR_U32(ctx, 2);
    // 0x1021dc: 0x8e020208  lw          $v0, 0x208($s0)
    ctx->pc = 0x1021dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 520)));
    // 0x1021e0: 0x48c29000  ctc2.ni     $v0, $vi18
    ctx->pc = 0x1021e0u;
    ctx->vu0_fbrst4 = GPR_U32(ctx, 2);
    // 0x1021e4: 0x8e02020c  lw          $v0, 0x20C($s0)
    ctx->pc = 0x1021e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 524)));
    // 0x1021e8: 0x48c2a000  ctc2.ni     $v0, $vi20
    ctx->pc = 0x1021e8u;
    ctx->vu0_acc = _mm_castsi128_ps(GPR_VEC(ctx, 2));
    // 0x1021ec: 0x8e020210  lw          $v0, 0x210($s0)
    ctx->pc = 0x1021ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 528)));
    // 0x1021f0: 0x48c2a800  ctc2.ni     $v0, $vi21
    ctx->pc = 0x1021f0u;
    ctx->vu0_info = GPR_U32(ctx, 2);
    // 0x1021f4: 0x8e020214  lw          $v0, 0x214($s0)
    ctx->pc = 0x1021f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 532)));
    // 0x1021f8: 0x48c2b000  ctc2.ni     $v0, $vi22
    ctx->pc = 0x1021f8u;
    ctx->vu0_clip_flags2 = GPR_U32(ctx, 2);
    // 0x1021fc: 0x96020218  lhu         $v0, 0x218($s0)
    ctx->pc = 0x1021fcu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 536)));
    // 0x102200: 0x48c20000  ctc2.ni     $v0, $vi0
    ctx->pc = 0x102200u;
    ctx->vu0_status = GPR_U32(ctx, 2) & 0xFFFF;
    // 0x102204: 0x9602021a  lhu         $v0, 0x21A($s0)
    ctx->pc = 0x102204u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 538)));
    // 0x102208: 0x48c20800  ctc2.ni     $v0, $vi1
    ctx->pc = 0x102208u;
    ctx->vu0_mac_flags = GPR_U32(ctx, 2);
    // 0x10220c: 0x9602021c  lhu         $v0, 0x21C($s0)
    ctx->pc = 0x10220cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 540)));
    // 0x102210: 0x48c21000  ctc2.ni     $v0, $vi2
    ctx->pc = 0x102210u;
    ctx->vu0_vpu_stat = GPR_U32(ctx, 2);
    // 0x102214: 0x9602021e  lhu         $v0, 0x21E($s0)
    ctx->pc = 0x102214u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 542)));
    // 0x102218: 0x48c21800  ctc2.ni     $v0, $vi3
    ctx->pc = 0x102218u;
    ctx->vu0_r = _mm_castsi128_ps(GPR_VEC(ctx, 2));
    // 0x10221c: 0x96020220  lhu         $v0, 0x220($s0)
    ctx->pc = 0x10221cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 544)));
    // 0x102220: 0x48c22000  ctc2.ni     $v0, $vi4
    ctx->pc = 0x102220u;
    { uint32_t tmp = GPR_U32(ctx, 2); std::memcpy(&ctx->vu0_i, &tmp, sizeof(tmp)); }
    // 0x102224: 0x96020222  lhu         $v0, 0x222($s0)
    ctx->pc = 0x102224u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 546)));
    // 0x102228: 0x48c22800  ctc2.ni     $v0, $vi5
    ctx->pc = 0x102228u;
    ctx->vu0_clip_flags = GPR_U32(ctx, 2);
    // 0x10222c: 0x96020224  lhu         $v0, 0x224($s0)
    ctx->pc = 0x10222cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 548)));
    // 0x102230: 0x48c23000  ctc2.ni     $v0, $vi6
    ctx->pc = 0x102230u;
    ctx->vu0_tpc = GPR_U32(ctx, 2);
    // 0x102234: 0x96020226  lhu         $v0, 0x226($s0)
    ctx->pc = 0x102234u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 550)));
    // 0x102238: 0x48c23800  ctc2.ni     $v0, $vi7
    ctx->pc = 0x102238u;
    ctx->vu0_cmsar0 = GPR_U32(ctx, 2);
    // 0x10223c: 0x96020228  lhu         $v0, 0x228($s0)
    ctx->pc = 0x10223cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 552)));
    // 0x102240: 0x48c24000  ctc2.ni     $v0, $vi8
    ctx->pc = 0x102240u;
    ctx->vu0_fbrst = GPR_U32(ctx, 2);
    // 0x102244: 0x9602022a  lhu         $v0, 0x22A($s0)
    ctx->pc = 0x102244u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 554)));
    // 0x102248: 0x48c24800  ctc2.ni     $v0, $vi9
    ctx->pc = 0x102248u;
    ctx->vu0_vpu_stat2 = GPR_U32(ctx, 2);
    // 0x10224c: 0x9602022c  lhu         $v0, 0x22C($s0)
    ctx->pc = 0x10224cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 556)));
    // 0x102250: 0x48c25000  ctc2.ni     $v0, $vi10
    ctx->pc = 0x102250u;
    ctx->vu0_tpc2 = GPR_U32(ctx, 2);
    // 0x102254: 0x9602022e  lhu         $v0, 0x22E($s0)
    ctx->pc = 0x102254u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 558)));
    // 0x102258: 0x48c25800  ctc2.ni     $v0, $vi11
    ctx->pc = 0x102258u;
    ctx->vu0_cmsar1 = GPR_U32(ctx, 2);
    // 0x10225c: 0x96020230  lhu         $v0, 0x230($s0)
    ctx->pc = 0x10225cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 560)));
    // 0x102260: 0x48c26000  ctc2.ni     $v0, $vi12
    ctx->pc = 0x102260u;
    ctx->vu0_fbrst2 = GPR_U32(ctx, 2);
    // 0x102264: 0x96020232  lhu         $v0, 0x232($s0)
    ctx->pc = 0x102264u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 562)));
    // 0x102268: 0x48c26800  ctc2.ni     $v0, $vi13
    ctx->pc = 0x102268u;
    ctx->vu0_vpu_stat3 = GPR_U32(ctx, 2);
    // 0x10226c: 0x96020234  lhu         $v0, 0x234($s0)
    ctx->pc = 0x10226cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 564)));
    // 0x102270: 0x48c27000  ctc2.ni     $v0, $vi14
    ctx->pc = 0x102270u;
    ctx->vu0_cmsar2 = GPR_U32(ctx, 2);
    // 0x102274: 0x96020236  lhu         $v0, 0x236($s0)
    ctx->pc = 0x102274u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 566)));
    // 0x102278: 0x48c27800  ctc2.ni     $v0, $vi15
    ctx->pc = 0x102278u;
    ctx->vu0_fbrst3 = GPR_U32(ctx, 2);
    // 0x10227c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10227cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_102280:
    // 0x102280: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x102280u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x102284: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x102284u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x102288: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x102288u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10228c: 0x3e00008  jr          $ra
    ctx->pc = 0x10228Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10228Cu;
            // 0x102290: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101FDCu: goto label_101fdc;
            case 0x102118u: goto label_102118;
            case 0x10214Cu: goto label_10214c;
            case 0x102280u: goto label_102280;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102294u;
    // 0x102294: 0x0  nop
    ctx->pc = 0x102294u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
