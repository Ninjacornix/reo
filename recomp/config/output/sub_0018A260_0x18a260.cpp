#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018A260
// Address: 0x18a260 - 0x18b2c0
void sub_0018A260_0x18a260(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018A260_0x18a260");
#endif

    switch (ctx->pc) {
        case 0x18a2c8u: goto label_18a2c8;
        case 0x18a2f0u: goto label_18a2f0;
        case 0x18a310u: goto label_18a310;
        case 0x18a39cu: goto label_18a39c;
        case 0x18a470u: goto label_18a470;
        case 0x18a4e8u: goto label_18a4e8;
        case 0x18a57cu: goto label_18a57c;
        case 0x18a5b4u: goto label_18a5b4;
        case 0x18a5ccu: goto label_18a5cc;
        case 0x18a628u: goto label_18a628;
        case 0x18a64cu: goto label_18a64c;
        case 0x18a6c0u: goto label_18a6c0;
        case 0x18a750u: goto label_18a750;
        case 0x18a788u: goto label_18a788;
        case 0x18a7c0u: goto label_18a7c0;
        case 0x18a80cu: goto label_18a80c;
        case 0x18a89cu: goto label_18a89c;
        case 0x18a8d4u: goto label_18a8d4;
        case 0x18aad4u: goto label_18aad4;
        case 0x18aaecu: goto label_18aaec;
        case 0x18aafcu: goto label_18aafc;
        case 0x18ab14u: goto label_18ab14;
        case 0x18ac14u: goto label_18ac14;
        case 0x18ac2cu: goto label_18ac2c;
        case 0x18ac3cu: goto label_18ac3c;
        case 0x18ac58u: goto label_18ac58;
        case 0x18ac70u: goto label_18ac70;
        case 0x18ac80u: goto label_18ac80;
        case 0x18ac98u: goto label_18ac98;
        case 0x18ae04u: goto label_18ae04;
        case 0x18ae1cu: goto label_18ae1c;
        case 0x18ae2cu: goto label_18ae2c;
        case 0x18ae48u: goto label_18ae48;
        case 0x18ae60u: goto label_18ae60;
        case 0x18ae70u: goto label_18ae70;
        case 0x18ae88u: goto label_18ae88;
        case 0x18b038u: goto label_18b038;
        case 0x18b108u: goto label_18b108;
        case 0x18b198u: goto label_18b198;
        case 0x18b1ccu: goto label_18b1cc;
        case 0x18b1e4u: goto label_18b1e4;
        case 0x18b240u: goto label_18b240;
        case 0x18b264u: goto label_18b264;
        case 0x18b28cu: goto label_18b28c;
        default: break;
    }

    ctx->pc = 0x18a260u;

    // 0x18a260: 0x27bdfcf0  addiu       $sp, $sp, -0x310
    ctx->pc = 0x18a260u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966512));
    // 0x18a264: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x18a264u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x18a268: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x18a268u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x18a26c: 0x7fbe0080  sq          $fp, 0x80($sp)
    ctx->pc = 0x18a26cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 30));
    // 0x18a270: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x18a270u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x18a274: 0xa0f02d  daddu       $fp, $a1, $zero
    ctx->pc = 0x18a274u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a278: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x18a278u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x18a27c: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x18a27cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x18a280: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x18a280u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x18a284: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x18a284u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x18a288: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x18a288u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x18a28c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x18a28cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x18a290: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18a290u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18a294: 0xafa4026c  sw          $a0, 0x26C($sp)
    ctx->pc = 0x18a294u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 620), GPR_U32(ctx, 4));
    // 0x18a298: 0x8ca2004c  lw          $v0, 0x4C($a1)
    ctx->pc = 0x18a298u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 76)));
    // 0x18a29c: 0x27a40300  addiu       $a0, $sp, 0x300
    ctx->pc = 0x18a29cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 768));
    // 0x18a2a0: 0xafa20180  sw          $v0, 0x180($sp)
    ctx->pc = 0x18a2a0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 384), GPR_U32(ctx, 2));
    // 0x18a2a4: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x18a2a4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x18a2a8: 0x8fa20180  lw          $v0, 0x180($sp)
    ctx->pc = 0x18a2a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 384)));
    // 0x18a2ac: 0x24a5fd64  addiu       $a1, $a1, -0x29C
    ctx->pc = 0x18a2acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294966628));
    // 0x18a2b0: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x18a2b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x18a2b4: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x18a2b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x18a2b8: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x18a2b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x18a2bc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x18a2bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18a2c0: 0x10800008  beqz        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x18A2C0u;
    {
        const bool branch_taken_0x18a2c0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x18A2C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A2C0u;
            // 0x18a2c4: 0xafa20170  sw          $v0, 0x170($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 368), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a2c0) {
            ctx->pc = 0x18A2E4u;
            goto label_18a2e4;
        }
    }
    ctx->pc = 0x18A2C8u;
label_18a2c8:
    // 0x18a2c8: 0xa0800000  sb          $zero, 0x0($a0)
    ctx->pc = 0x18a2c8u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x18a2cc: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x18a2ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x18a2d0: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x18a2d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x18a2d4: 0x0  nop
    ctx->pc = 0x18a2d4u;
    // NOP
    // 0x18a2d8: 0x0  nop
    ctx->pc = 0x18a2d8u;
    // NOP
    // 0x18a2dc: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x18A2DCu;
    {
        const bool branch_taken_0x18a2dc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x18a2dc) {
            ctx->pc = 0x18A2C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18a2c8;
        }
    }
    ctx->pc = 0x18A2E4u;
label_18a2e4:
    // 0x18a2e4: 0x27a302f0  addiu       $v1, $sp, 0x2F0
    ctx->pc = 0x18a2e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 752));
    // 0x18a2e8: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x18A2E8u;
    {
        const bool branch_taken_0x18a2e8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x18A2ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A2E8u;
            // 0x18a2ec: 0x24020010  addiu       $v0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a2e8) {
            ctx->pc = 0x18A30Cu;
            goto label_18a30c;
        }
    }
    ctx->pc = 0x18A2F0u;
label_18a2f0:
    // 0x18a2f0: 0xa0600000  sb          $zero, 0x0($v1)
    ctx->pc = 0x18a2f0u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x18a2f4: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x18a2f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x18a2f8: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x18a2f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x18a2fc: 0x0  nop
    ctx->pc = 0x18a2fcu;
    // NOP
    // 0x18a300: 0x0  nop
    ctx->pc = 0x18a300u;
    // NOP
    // 0x18a304: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x18A304u;
    {
        const bool branch_taken_0x18a304 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18a304) {
            ctx->pc = 0x18A2F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18a2f0;
        }
    }
    ctx->pc = 0x18A30Cu;
label_18a30c:
    // 0x18a30c: 0x2403001f  addiu       $v1, $zero, 0x1F
    ctx->pc = 0x18a30cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
label_18a310:
    // 0x18a310: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x18a310u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18a314: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x18a314u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x18a318: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x18a318u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x18a31c: 0xac400270  sw          $zero, 0x270($v0)
    ctx->pc = 0x18a31cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 624), GPR_U32(ctx, 0));
    // 0x18a320: 0x0  nop
    ctx->pc = 0x18a320u;
    // NOP
    // 0x18a324: 0x461fffa  bgez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x18A324u;
    {
        const bool branch_taken_0x18a324 = (GPR_S64(ctx, 3) >= 0);
        if (branch_taken_0x18a324) {
            ctx->pc = 0x18A310u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18a310;
        }
    }
    ctx->pc = 0x18A32Cu;
    // 0x18a32c: 0x8fa20180  lw          $v0, 0x180($sp)
    ctx->pc = 0x18a32cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 384)));
    // 0x18a330: 0x3c070023  lui         $a3, 0x23
    ctx->pc = 0x18a330u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)35 << 16));
    // 0x18a334: 0x3c060023  lui         $a2, 0x23
    ctx->pc = 0x18a334u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)35 << 16));
    // 0x18a338: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x18a338u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x18a33c: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x18a33cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x18a340: 0x24e7fdc0  addiu       $a3, $a3, -0x240
    ctx->pc = 0x18a340u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294966720));
    // 0x18a344: 0x24c6fdc4  addiu       $a2, $a2, -0x23C
    ctx->pc = 0x18a344u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294966724));
    // 0x18a348: 0x24a5fdc8  addiu       $a1, $a1, -0x238
    ctx->pc = 0x18a348u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294966728));
    // 0x18a34c: 0x34038000  ori         $v1, $zero, 0x8000
    ctx->pc = 0x18a34cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x18a350: 0x8c49001c  lw          $t1, 0x1C($v0)
    ctx->pc = 0x18a350u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x18a354: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x18a354u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x18a358: 0x94040  sll         $t0, $t1, 1
    ctx->pc = 0x18a358u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
    // 0x18a35c: 0x34428000  ori         $v0, $v0, 0x8000
    ctx->pc = 0x18a35cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32768);
    // 0x18a360: 0x1094021  addu        $t0, $t0, $t1
    ctx->pc = 0x18a360u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 9)));
    // 0x18a364: 0x84080  sll         $t0, $t0, 2
    ctx->pc = 0x18a364u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x18a368: 0x822024  and         $a0, $a0, $v0
    ctx->pc = 0x18a368u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x18a36c: 0xe83821  addu        $a3, $a3, $t0
    ctx->pc = 0x18a36cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x18a370: 0xc81021  addu        $v0, $a2, $t0
    ctx->pc = 0x18a370u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x18a374: 0x8cf20000  lw          $s2, 0x0($a3)
    ctx->pc = 0x18a374u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x18a378: 0xa82821  addu        $a1, $a1, $t0
    ctx->pc = 0x18a378u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
    // 0x18a37c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x18a37cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18a380: 0xafa201a0  sw          $v0, 0x1A0($sp)
    ctx->pc = 0x18a380u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 416), GPR_U32(ctx, 2));
    // 0x18a384: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x18a384u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x18a388: 0x14830002  bne         $a0, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x18A388u;
    {
        const bool branch_taken_0x18a388 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x18A38Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A388u;
            // 0x18a38c: 0xafa20190  sw          $v0, 0x190($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 400), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a388) {
            ctx->pc = 0x18A394u;
            goto label_18a394;
        }
    }
    ctx->pc = 0x18A390u;
    // 0x18a390: 0x36520020  ori         $s2, $s2, 0x20
    ctx->pc = 0x18a390u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | (uint64_t)(uint16_t)32);
label_18a394:
    // 0x18a394: 0xc063728  jal         func_18DCA0
    ctx->pc = 0x18A394u;
    SET_GPR_U32(ctx, 31, 0x18A39Cu);
    ctx->pc = 0x18A398u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18A394u;
            // 0x18a398: 0x8fc4001c  lw          $a0, 0x1C($fp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DCA0u;
    if (runtime->hasFunction(0x18DCA0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A39Cu; }
        if (ctx->pc != 0x18A39Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A39Cu; }
        if (ctx->pc != 0x18A39Cu) { return; }
    }
    ctx->pc = 0x18A39Cu;
label_18a39c:
    // 0x18a39c: 0x12183c  dsll32      $v1, $s2, 0
    ctx->pc = 0x18a39cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) << (32 + 0));
    // 0x18a3a0: 0xafa2024c  sw          $v0, 0x24C($sp)
    ctx->pc = 0x18a3a0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 588), GPR_U32(ctx, 2));
    // 0x18a3a4: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x18a3a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x18a3a8: 0x8fa50190  lw          $a1, 0x190($sp)
    ctx->pc = 0x18a3a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 400)));
    // 0x18a3ac: 0x31bfc  dsll32      $v1, $v1, 15
    ctx->pc = 0x18a3acu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 15));
    // 0x18a3b0: 0x8fb5024c  lw          $s5, 0x24C($sp)
    ctx->pc = 0x18a3b0u;
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 588)));
    // 0x18a3b4: 0xffa30130  sd          $v1, 0x130($sp)
    ctx->pc = 0x18a3b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 304), GPR_U64(ctx, 3));
    // 0x18a3b8: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x18a3b8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a3bc: 0x8fa3026c  lw          $v1, 0x26C($sp)
    ctx->pc = 0x18a3bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 620)));
    // 0x18a3c0: 0x52900  sll         $a1, $a1, 4
    ctx->pc = 0x18a3c0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x18a3c4: 0x8c720008  lw          $s2, 0x8($v1)
    ctx->pc = 0x18a3c4u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x18a3c8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x18a3c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x18a3cc: 0xafa30230  sw          $v1, 0x230($sp)
    ctx->pc = 0x18a3ccu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 560), GPR_U32(ctx, 3));
    // 0x18a3d0: 0x8fa3026c  lw          $v1, 0x26C($sp)
    ctx->pc = 0x18a3d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 620)));
    // 0x18a3d4: 0x8c630004  lw          $v1, 0x4($v1)
    ctx->pc = 0x18a3d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x18a3d8: 0xafa301d0  sw          $v1, 0x1D0($sp)
    ctx->pc = 0x18a3d8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 464), GPR_U32(ctx, 3));
    // 0x18a3dc: 0x8fa30180  lw          $v1, 0x180($sp)
    ctx->pc = 0x18a3dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 384)));
    // 0x18a3e0: 0xafa00220  sw          $zero, 0x220($sp)
    ctx->pc = 0x18a3e0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 544), GPR_U32(ctx, 0));
    // 0x18a3e4: 0x8c640020  lw          $a0, 0x20($v1)
    ctx->pc = 0x18a3e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x18a3e8: 0x8fa30230  lw          $v1, 0x230($sp)
    ctx->pc = 0x18a3e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 560)));
    // 0x18a3ec: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x18a3ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x18a3f0: 0xafa00200  sw          $zero, 0x200($sp)
    ctx->pc = 0x18a3f0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 512), GPR_U32(ctx, 0));
    // 0x18a3f4: 0xafa30210  sw          $v1, 0x210($sp)
    ctx->pc = 0x18a3f4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 528), GPR_U32(ctx, 3));
    // 0x18a3f8: 0x8fc3002c  lw          $v1, 0x2C($fp)
    ctx->pc = 0x18a3f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x18a3fc: 0xafa50140  sw          $a1, 0x140($sp)
    ctx->pc = 0x18a3fcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 320), GPR_U32(ctx, 5));
    // 0x18a400: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x18a400u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18a404: 0x8fa50190  lw          $a1, 0x190($sp)
    ctx->pc = 0x18a404u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 400)));
    // 0x18a408: 0xafa40150  sw          $a0, 0x150($sp)
    ctx->pc = 0x18a408u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 336), GPR_U32(ctx, 4));
    // 0x18a40c: 0x8fa40170  lw          $a0, 0x170($sp)
    ctx->pc = 0x18a40cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 368)));
    // 0x18a410: 0xafa000a0  sw          $zero, 0xA0($sp)
    ctx->pc = 0x18a410u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 160), GPR_U32(ctx, 0));
    // 0x18a414: 0xafa201b0  sw          $v0, 0x1B0($sp)
    ctx->pc = 0x18a414u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 432), GPR_U32(ctx, 2));
    // 0x18a418: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x18a418u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x18a41c: 0x5283e  dsrl32      $a1, $a1, 0
    ctx->pc = 0x18a41cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
    // 0x18a420: 0x52f3c  dsll32      $a1, $a1, 28
    ctx->pc = 0x18a420u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 28));
    // 0x18a424: 0x30840008  andi        $a0, $a0, 0x8
    ctx->pc = 0x18a424u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)8);
    // 0x18a428: 0xffa50120  sd          $a1, 0x120($sp)
    ctx->pc = 0x18a428u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 288), GPR_U64(ctx, 5));
    // 0x18a42c: 0x8fa50170  lw          $a1, 0x170($sp)
    ctx->pc = 0x18a42cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 368)));
    // 0x18a430: 0xafa400e0  sw          $a0, 0xE0($sp)
    ctx->pc = 0x18a430u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 224), GPR_U32(ctx, 4));
    // 0x18a434: 0x8fa40170  lw          $a0, 0x170($sp)
    ctx->pc = 0x18a434u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 368)));
    // 0x18a438: 0x30a50001  andi        $a1, $a1, 0x1
    ctx->pc = 0x18a438u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)1);
    // 0x18a43c: 0xafa50110  sw          $a1, 0x110($sp)
    ctx->pc = 0x18a43cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 272), GPR_U32(ctx, 5));
    // 0x18a440: 0x8fa50170  lw          $a1, 0x170($sp)
    ctx->pc = 0x18a440u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 368)));
    // 0x18a444: 0x30840010  andi        $a0, $a0, 0x10
    ctx->pc = 0x18a444u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)16);
    // 0x18a448: 0xafa400d0  sw          $a0, 0xD0($sp)
    ctx->pc = 0x18a448u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 208), GPR_U32(ctx, 4));
    // 0x18a44c: 0x8fa40170  lw          $a0, 0x170($sp)
    ctx->pc = 0x18a44cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 368)));
    // 0x18a450: 0x30a50002  andi        $a1, $a1, 0x2
    ctx->pc = 0x18a450u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)2);
    // 0x18a454: 0xafa50100  sw          $a1, 0x100($sp)
    ctx->pc = 0x18a454u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 256), GPR_U32(ctx, 5));
    // 0x18a458: 0x8fa50170  lw          $a1, 0x170($sp)
    ctx->pc = 0x18a458u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 368)));
    // 0x18a45c: 0x30840020  andi        $a0, $a0, 0x20
    ctx->pc = 0x18a45cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32);
    // 0x18a460: 0xafa400c0  sw          $a0, 0xC0($sp)
    ctx->pc = 0x18a460u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 192), GPR_U32(ctx, 4));
    // 0x18a464: 0x30a50004  andi        $a1, $a1, 0x4
    ctx->pc = 0x18a464u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)4);
    // 0x18a468: 0x1000031b  b           . + 4 + (0x31B << 2)
    ctx->pc = 0x18A468u;
    {
        const bool branch_taken_0x18a468 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18A46Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A468u;
            // 0x18a46c: 0xafa500f0  sw          $a1, 0xF0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 240), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a468) {
            ctx->pc = 0x18B0D8u;
            goto label_18b0d8;
        }
    }
    ctx->pc = 0x18A470u;
label_18a470:
    // 0x18a470: 0x96420000  lhu         $v0, 0x0($s2)
    ctx->pc = 0x18a470u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18a474: 0xafa201c0  sw          $v0, 0x1C0($sp)
    ctx->pc = 0x18a474u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 448), GPR_U32(ctx, 2));
    // 0x18a478: 0x8fa2026c  lw          $v0, 0x26C($sp)
    ctx->pc = 0x18a478u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 620)));
    // 0x18a47c: 0xafa00160  sw          $zero, 0x160($sp)
    ctx->pc = 0x18a47cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 352), GPR_U32(ctx, 0));
    // 0x18a480: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x18a480u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18a484: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x18a484u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x18a488: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x18a488u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x18a48c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18A48Cu;
    {
        const bool branch_taken_0x18a48c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x18A490u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A48Cu;
            // 0x18a490: 0x26520002  addiu       $s2, $s2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a48c) {
            ctx->pc = 0x18A4A0u;
            goto label_18a4a0;
        }
    }
    ctx->pc = 0x18A494u;
    // 0x18a494: 0x96420000  lhu         $v0, 0x0($s2)
    ctx->pc = 0x18a494u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18a498: 0xafa20220  sw          $v0, 0x220($sp)
    ctx->pc = 0x18a498u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 544), GPR_U32(ctx, 2));
    // 0x18a49c: 0x26520002  addiu       $s2, $s2, 0x2
    ctx->pc = 0x18a49cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
label_18a4a0:
    // 0x18a4a0: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x18a4a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x18a4a4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x18a4a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x18a4a8: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18A4A8u;
    {
        const bool branch_taken_0x18a4a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18a4a8) {
            ctx->pc = 0x18A4BCu;
            goto label_18a4bc;
        }
    }
    ctx->pc = 0x18A4B0u;
    // 0x18a4b0: 0x96420000  lhu         $v0, 0x0($s2)
    ctx->pc = 0x18a4b0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18a4b4: 0xafa20200  sw          $v0, 0x200($sp)
    ctx->pc = 0x18a4b4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 512), GPR_U32(ctx, 2));
    // 0x18a4b8: 0x26520002  addiu       $s2, $s2, 0x2
    ctx->pc = 0x18a4b8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
label_18a4bc:
    // 0x18a4bc: 0x8fa30230  lw          $v1, 0x230($sp)
    ctx->pc = 0x18a4bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 560)));
    // 0x18a4c0: 0x8fa20220  lw          $v0, 0x220($sp)
    ctx->pc = 0x18a4c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 544)));
    // 0x18a4c4: 0x10620073  beq         $v1, $v0, . + 4 + (0x73 << 2)
    ctx->pc = 0x18A4C4u;
    {
        const bool branch_taken_0x18a4c4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x18a4c4) {
            ctx->pc = 0x18A694u;
            goto label_18a694;
        }
    }
    ctx->pc = 0x18A4CCu;
    // 0x18a4cc: 0x12600060  beqz        $s3, . + 4 + (0x60 << 2)
    ctx->pc = 0x18A4CCu;
    {
        const bool branch_taken_0x18a4cc = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        if (branch_taken_0x18a4cc) {
            ctx->pc = 0x18A650u;
            goto label_18a650;
        }
    }
    ctx->pc = 0x18A4D4u;
    // 0x18a4d4: 0x8fa201f0  lw          $v0, 0x1F0($sp)
    ctx->pc = 0x18a4d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 496)));
    // 0x18a4d8: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x18a4d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a4dc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x18a4dcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a4e0: 0xc063204  jal         func_18C810
    ctx->pc = 0x18A4E0u;
    SET_GPR_U32(ctx, 31, 0x18A4E8u);
    ctx->pc = 0x18A4E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18A4E0u;
            // 0x18a4e4: 0x22902  srl         $a1, $v0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C810u;
    if (runtime->hasFunction(0x18C810u)) {
        auto targetFn = runtime->lookupFunction(0x18C810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A4E8u; }
        if (ctx->pc != 0x18A4E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C810_0x18c810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A4E8u; }
        if (ctx->pc != 0x18A4E8u) { return; }
    }
    ctx->pc = 0x18A4E8u;
label_18a4e8:
    // 0x18a4e8: 0x40b82d  daddu       $s7, $v0, $zero
    ctx->pc = 0x18a4e8u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a4ec: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x18a4ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18a4f0: 0x8fa20210  lw          $v0, 0x210($sp)
    ctx->pc = 0x18a4f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 528)));
    // 0x18a4f4: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x18A4F4u;
    {
        const bool branch_taken_0x18a4f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x18a4f4) {
            ctx->pc = 0x18A514u;
            goto label_18a514;
        }
    }
    ctx->pc = 0x18A4FCu;
    // 0x18a4fc: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18A4FCu;
    {
        const bool branch_taken_0x18a4fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18a4fc) {
            ctx->pc = 0x18A50Cu;
            goto label_18a50c;
        }
    }
    ctx->pc = 0x18A504u;
    // 0x18a504: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x18A504u;
    {
        const bool branch_taken_0x18a504 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18A508u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A504u;
            // 0x18a508: 0x8fa20140  lw          $v0, 0x140($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 320)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a504) {
            ctx->pc = 0x18A520u;
            goto label_18a520;
        }
    }
    ctx->pc = 0x18A50Cu;
label_18a50c:
    // 0x18a50c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x18A50Cu;
    {
        const bool branch_taken_0x18a50c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18A510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A50Cu;
            // 0x18a510: 0xaee30000  sw          $v1, 0x0($s7) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 23), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a50c) {
            ctx->pc = 0x18A51Cu;
            goto label_18a51c;
        }
    }
    ctx->pc = 0x18A514u;
label_18a514:
    // 0x18a514: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x18a514u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x18a518: 0xaee20000  sw          $v0, 0x0($s7)
    ctx->pc = 0x18a518u;
    WRITE32(ADD32(GPR_U32(ctx, 23), 0), GPR_U32(ctx, 2));
label_18a51c:
    // 0x18a51c: 0x8fa20140  lw          $v0, 0x140($sp)
    ctx->pc = 0x18a51cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 320)));
label_18a520:
    // 0x18a520: 0x26630002  addiu       $v1, $s3, 0x2
    ctx->pc = 0x18a520u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
    // 0x18a524: 0x13283c  dsll32      $a1, $s3, 0
    ctx->pc = 0x18a524u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 19) << (32 + 0));
    // 0x18a528: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x18a528u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a52c: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x18a52cu;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x18a530: 0x433018  mult        $a2, $v0, $v1
    ctx->pc = 0x18a530u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 6, (int32_t)result); }
    // 0x18a534: 0x24034000  addiu       $v1, $zero, 0x4000
    ctx->pc = 0x18a534u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x18a538: 0x34028000  ori         $v0, $zero, 0x8000
    ctx->pc = 0x18a538u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x18a53c: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x18a53cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x18a540: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x18a540u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x18a544: 0xa21825  or          $v1, $a1, $v0
    ctx->pc = 0x18a544u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x18a548: 0x61102  srl         $v0, $a2, 4
    ctx->pc = 0x18a548u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), 4));
    // 0x18a54c: 0x24450001  addiu       $a1, $v0, 0x1
    ctx->pc = 0x18a54cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x18a550: 0xdfa20130  ld          $v0, 0x130($sp)
    ctx->pc = 0x18a550u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x18a554: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x18a554u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x18a558: 0xaee50004  sw          $a1, 0x4($s7)
    ctx->pc = 0x18a558u;
    WRITE32(ADD32(GPR_U32(ctx, 23), 4), GPR_U32(ctx, 5));
    // 0x18a55c: 0xdfa20120  ld          $v0, 0x120($sp)
    ctx->pc = 0x18a55cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 29), 288)));
    // 0x18a560: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x18a560u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x18a564: 0xfee00008  sd          $zero, 0x8($s7)
    ctx->pc = 0x18a564u;
    WRITE64(ADD32(GPR_U32(ctx, 23), 8), GPR_U64(ctx, 0));
    // 0x18a568: 0xfee20010  sd          $v0, 0x10($s7)
    ctx->pc = 0x18a568u;
    WRITE64(ADD32(GPR_U32(ctx, 23), 16), GPR_U64(ctx, 2));
    // 0x18a56c: 0x8fa201a0  lw          $v0, 0x1A0($sp)
    ctx->pc = 0x18a56cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 416)));
    // 0x18a570: 0xaee20018  sw          $v0, 0x18($s7)
    ctx->pc = 0x18a570u;
    WRITE32(ADD32(GPR_U32(ctx, 23), 24), GPR_U32(ctx, 2));
    // 0x18a574: 0xc0631fc  jal         func_18C7F0
    ctx->pc = 0x18A574u;
    SET_GPR_U32(ctx, 31, 0x18A57Cu);
    ctx->pc = 0x18A578u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18A574u;
            // 0x18a578: 0xaee0001c  sw          $zero, 0x1C($s7) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 23), 28), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C7F0u;
    if (runtime->hasFunction(0x18C7F0u)) {
        auto targetFn = runtime->lookupFunction(0x18C7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A57Cu; }
        if (ctx->pc != 0x18A57Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7F0_0x18c7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A57Cu; }
        if (ctx->pc != 0x18A57Cu) { return; }
    }
    ctx->pc = 0x18A57Cu;
label_18a57c:
    // 0x18a57c: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x18a57cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a580: 0x8fa20230  lw          $v0, 0x230($sp)
    ctx->pc = 0x18a580u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 560)));
    // 0x18a584: 0x29880  sll         $s3, $v0, 2
    ctx->pc = 0x18a584u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x18a588: 0x27d1021  addu        $v0, $s3, $sp
    ctx->pc = 0x18a588u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 29)));
    // 0x18a58c: 0x8c440270  lw          $a0, 0x270($v0)
    ctx->pc = 0x18a58cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 624)));
    // 0x18a590: 0x1684000e  bne         $s4, $a0, . + 4 + (0xE << 2)
    ctx->pc = 0x18A590u;
    {
        const bool branch_taken_0x18a590 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 4));
        if (branch_taken_0x18a590) {
            ctx->pc = 0x18A5CCu;
            goto label_18a5cc;
        }
    }
    ctx->pc = 0x18A598u;
    // 0x18a598: 0x2b41023  subu        $v0, $s5, $s4
    ctx->pc = 0x18a598u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 20)));
    // 0x18a59c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x18a59cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a5a0: 0x21102  srl         $v0, $v0, 4
    ctx->pc = 0x18a5a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
    // 0x18a5a4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x18a5a4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a5a8: 0x2445ffff  addiu       $a1, $v0, -0x1
    ctx->pc = 0x18a5a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x18a5ac: 0xc0631e4  jal         func_18C790
    ctx->pc = 0x18A5ACu;
    SET_GPR_U32(ctx, 31, 0x18A5B4u);
    ctx->pc = 0x18A5B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18A5ACu;
            // 0x18a5b0: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C790u;
    if (runtime->hasFunction(0x18C790u)) {
        auto targetFn = runtime->lookupFunction(0x18C790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A5B4u; }
        if (ctx->pc != 0x18A5B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C790_0x18c790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A5B4u; }
        if (ctx->pc != 0x18A5B4u) { return; }
    }
    ctx->pc = 0x18A5B4u;
label_18a5b4:
    // 0x18a5b4: 0x8fa2024c  lw          $v0, 0x24C($sp)
    ctx->pc = 0x18a5b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 588)));
    // 0x18a5b8: 0x2821823  subu        $v1, $s4, $v0
    ctx->pc = 0x18a5b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
    // 0x18a5bc: 0x8fa201b0  lw          $v0, 0x1B0($sp)
    ctx->pc = 0x18a5bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 432)));
    // 0x18a5c0: 0x531021  addu        $v0, $v0, $s3
    ctx->pc = 0x18a5c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x18a5c4: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x18A5C4u;
    {
        const bool branch_taken_0x18a5c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18A5C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A5C4u;
            // 0x18a5c8: 0xac430000  sw          $v1, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a5c4) {
            ctx->pc = 0x18A64Cu;
            goto label_18a64c;
        }
    }
    ctx->pc = 0x18A5CCu;
label_18a5cc:
    // 0x18a5cc: 0x8c850000  lw          $a1, 0x0($a0)
    ctx->pc = 0x18a5ccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18a5d0: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x18a5d0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x18a5d4: 0x3c026000  lui         $v0, 0x6000
    ctx->pc = 0x18a5d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)24576 << 16));
    // 0x18a5d8: 0xa31824  and         $v1, $a1, $v1
    ctx->pc = 0x18a5d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x18a5dc: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x18A5DCu;
    {
        const bool branch_taken_0x18a5dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x18A5E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A5DCu;
            // 0x18a5e0: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a5dc) {
            ctx->pc = 0x18A614u;
            goto label_18a614;
        }
    }
    ctx->pc = 0x18A5E4u;
    // 0x18a5e4: 0x10620006  beq         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x18A5E4u;
    {
        const bool branch_taken_0x18a5e4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x18a5e4) {
            ctx->pc = 0x18A600u;
            goto label_18a600;
        }
    }
    ctx->pc = 0x18A5ECu;
    // 0x18a5ec: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x18a5ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x18a5f0: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18A5F0u;
    {
        const bool branch_taken_0x18a5f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x18A5F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A5F0u;
            // 0x18a5f4: 0x30a2ffff  andi        $v0, $a1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a5f0) {
            ctx->pc = 0x18A604u;
            goto label_18a604;
        }
    }
    ctx->pc = 0x18A5F8u;
    // 0x18a5f8: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x18A5F8u;
    {
        const bool branch_taken_0x18a5f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18a5f8) {
            ctx->pc = 0x18A62Cu;
            goto label_18a62c;
        }
    }
    ctx->pc = 0x18A600u;
label_18a600:
    // 0x18a600: 0x30a2ffff  andi        $v0, $a1, 0xFFFF
    ctx->pc = 0x18a600u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
label_18a604:
    // 0x18a604: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x18a604u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x18a608: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x18a608u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x18a60c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x18A60Cu;
    {
        const bool branch_taken_0x18a60c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18A610u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A60Cu;
            // 0x18a610: 0x822021  addu        $a0, $a0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a60c) {
            ctx->pc = 0x18A62Cu;
            goto label_18a62c;
        }
    }
    ctx->pc = 0x18A614u;
label_18a614:
    // 0x18a614: 0x30a5ffff  andi        $a1, $a1, 0xFFFF
    ctx->pc = 0x18a614u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x18a618: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x18a618u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a61c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x18a61cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a620: 0xc063188  jal         func_18C620
    ctx->pc = 0x18A620u;
    SET_GPR_U32(ctx, 31, 0x18A628u);
    ctx->pc = 0x18A624u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18A620u;
            // 0x18a624: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C620u;
    if (runtime->hasFunction(0x18C620u)) {
        auto targetFn = runtime->lookupFunction(0x18C620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A628u; }
        if (ctx->pc != 0x18A628u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C620_0x18c620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A628u; }
        if (ctx->pc != 0x18A628u) { return; }
    }
    ctx->pc = 0x18A628u;
label_18a628:
    // 0x18a628: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x18a628u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18a62c:
    // 0x18a62c: 0x1480ffe7  bnez        $a0, . + 4 + (-0x19 << 2)
    ctx->pc = 0x18A62Cu;
    {
        const bool branch_taken_0x18a62c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x18A630u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A62Cu;
            // 0x18a630: 0x2b41023  subu        $v0, $s5, $s4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a62c) {
            ctx->pc = 0x18A5CCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18a5cc;
        }
    }
    ctx->pc = 0x18A634u;
    // 0x18a634: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x18a634u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a638: 0x21102  srl         $v0, $v0, 4
    ctx->pc = 0x18a638u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
    // 0x18a63c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x18a63cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a640: 0x2445ffff  addiu       $a1, $v0, -0x1
    ctx->pc = 0x18a640u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x18a644: 0xc0631e4  jal         func_18C790
    ctx->pc = 0x18A644u;
    SET_GPR_U32(ctx, 31, 0x18A64Cu);
    ctx->pc = 0x18A648u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18A644u;
            // 0x18a648: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C790u;
    if (runtime->hasFunction(0x18C790u)) {
        auto targetFn = runtime->lookupFunction(0x18C790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A64Cu; }
        if (ctx->pc != 0x18A64Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C790_0x18c790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A64Cu; }
        if (ctx->pc != 0x18A64Cu) { return; }
    }
    ctx->pc = 0x18A64Cu;
label_18a64c:
    // 0x18a64c: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x18a64cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18a650:
    // 0x18a650: 0x8fa20220  lw          $v0, 0x220($sp)
    ctx->pc = 0x18a650u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 544)));
    // 0x18a654: 0xafa20230  sw          $v0, 0x230($sp)
    ctx->pc = 0x18a654u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 560), GPR_U32(ctx, 2));
    // 0x18a658: 0x8fa20200  lw          $v0, 0x200($sp)
    ctx->pc = 0x18a658u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 512)));
    // 0x18a65c: 0xafa20210  sw          $v0, 0x210($sp)
    ctx->pc = 0x18a65cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 528), GPR_U32(ctx, 2));
    // 0x18a660: 0x8fa20220  lw          $v0, 0x220($sp)
    ctx->pc = 0x18a660u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 544)));
    // 0x18a664: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x18a664u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x18a668: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x18a668u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x18a66c: 0x24430270  addiu       $v1, $v0, 0x270
    ctx->pc = 0x18a66cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 624));
    // 0x18a670: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x18a670u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x18a674: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x18A674u;
    {
        const bool branch_taken_0x18a674 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18A678u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A674u;
            // 0x18a678: 0x2a0a02d  daddu       $s4, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a674) {
            ctx->pc = 0x18A680u;
            goto label_18a680;
        }
    }
    ctx->pc = 0x18A67Cu;
    // 0x18a67c: 0xac750000  sw          $s5, 0x0($v1)
    ctx->pc = 0x18a67cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 21));
label_18a680:
    // 0x18a680: 0x26b70010  addiu       $s7, $s5, 0x10
    ctx->pc = 0x18a680u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 21), 16));
    // 0x18a684: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x18a684u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x18a688: 0xafa201f0  sw          $v0, 0x1F0($sp)
    ctx->pc = 0x18a688u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 496), GPR_U32(ctx, 2));
    // 0x18a68c: 0x10000047  b           . + 4 + (0x47 << 2)
    ctx->pc = 0x18A68Cu;
    {
        const bool branch_taken_0x18a68c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18A690u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A68Cu;
            // 0x18a690: 0x26b50040  addiu       $s5, $s5, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a68c) {
            ctx->pc = 0x18A7ACu;
            goto label_18a7ac;
        }
    }
    ctx->pc = 0x18A694u;
label_18a694:
    // 0x18a694: 0x8fa30210  lw          $v1, 0x210($sp)
    ctx->pc = 0x18a694u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 528)));
    // 0x18a698: 0x8fa20200  lw          $v0, 0x200($sp)
    ctx->pc = 0x18a698u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 512)));
    // 0x18a69c: 0x10620043  beq         $v1, $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x18A69Cu;
    {
        const bool branch_taken_0x18a69c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x18a69c) {
            ctx->pc = 0x18A7ACu;
            goto label_18a7ac;
        }
    }
    ctx->pc = 0x18A6A4u;
    // 0x18a6a4: 0x1260003b  beqz        $s3, . + 4 + (0x3B << 2)
    ctx->pc = 0x18A6A4u;
    {
        const bool branch_taken_0x18a6a4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        if (branch_taken_0x18a6a4) {
            ctx->pc = 0x18A794u;
            goto label_18a794;
        }
    }
    ctx->pc = 0x18A6ACu;
    // 0x18a6ac: 0x8fa201f0  lw          $v0, 0x1F0($sp)
    ctx->pc = 0x18a6acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 496)));
    // 0x18a6b0: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x18a6b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a6b4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x18a6b4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a6b8: 0xc063204  jal         func_18C810
    ctx->pc = 0x18A6B8u;
    SET_GPR_U32(ctx, 31, 0x18A6C0u);
    ctx->pc = 0x18A6BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18A6B8u;
            // 0x18a6bc: 0x22902  srl         $a1, $v0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C810u;
    if (runtime->hasFunction(0x18C810u)) {
        auto targetFn = runtime->lookupFunction(0x18C810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A6C0u; }
        if (ctx->pc != 0x18A6C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C810_0x18c810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A6C0u; }
        if (ctx->pc != 0x18A6C0u) { return; }
    }
    ctx->pc = 0x18A6C0u;
label_18a6c0:
    // 0x18a6c0: 0x8fa30210  lw          $v1, 0x210($sp)
    ctx->pc = 0x18a6c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 528)));
    // 0x18a6c4: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x18a6c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18a6c8: 0x10640007  beq         $v1, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x18A6C8u;
    {
        const bool branch_taken_0x18a6c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x18a6c8) {
            ctx->pc = 0x18A6E8u;
            goto label_18a6e8;
        }
    }
    ctx->pc = 0x18A6D0u;
    // 0x18a6d0: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x18A6D0u;
    {
        const bool branch_taken_0x18a6d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x18a6d0) {
            ctx->pc = 0x18A6E0u;
            goto label_18a6e0;
        }
    }
    ctx->pc = 0x18A6D8u;
    // 0x18a6d8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x18A6D8u;
    {
        const bool branch_taken_0x18a6d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18A6DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A6D8u;
            // 0x18a6dc: 0x8fa30140  lw          $v1, 0x140($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 320)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a6d8) {
            ctx->pc = 0x18A6F4u;
            goto label_18a6f4;
        }
    }
    ctx->pc = 0x18A6E0u;
label_18a6e0:
    // 0x18a6e0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x18A6E0u;
    {
        const bool branch_taken_0x18a6e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18A6E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A6E0u;
            // 0x18a6e4: 0xac440000  sw          $a0, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a6e0) {
            ctx->pc = 0x18A6F0u;
            goto label_18a6f0;
        }
    }
    ctx->pc = 0x18A6E8u;
label_18a6e8:
    // 0x18a6e8: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x18a6e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x18a6ec: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x18a6ecu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
label_18a6f0:
    // 0x18a6f0: 0x8fa30140  lw          $v1, 0x140($sp)
    ctx->pc = 0x18a6f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 320)));
label_18a6f4:
    // 0x18a6f4: 0x26650002  addiu       $a1, $s3, 0x2
    ctx->pc = 0x18a6f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
    // 0x18a6f8: 0x13303c  dsll32      $a2, $s3, 0
    ctx->pc = 0x18a6f8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 19) << (32 + 0));
    // 0x18a6fc: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x18a6fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a700: 0x6303f  dsra32      $a2, $a2, 0
    ctx->pc = 0x18a700u;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 0));
    // 0x18a704: 0x653818  mult        $a3, $v1, $a1
    ctx->pc = 0x18a704u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 7, (int32_t)result); }
    // 0x18a708: 0x24054000  addiu       $a1, $zero, 0x4000
    ctx->pc = 0x18a708u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x18a70c: 0x34038000  ori         $v1, $zero, 0x8000
    ctx->pc = 0x18a70cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x18a710: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x18a710u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x18a714: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x18a714u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x18a718: 0xc32825  or          $a1, $a2, $v1
    ctx->pc = 0x18a718u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x18a71c: 0x71902  srl         $v1, $a3, 4
    ctx->pc = 0x18a71cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 7), 4));
    // 0x18a720: 0x24660001  addiu       $a2, $v1, 0x1
    ctx->pc = 0x18a720u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x18a724: 0xdfa30130  ld          $v1, 0x130($sp)
    ctx->pc = 0x18a724u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x18a728: 0xa32825  or          $a1, $a1, $v1
    ctx->pc = 0x18a728u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x18a72c: 0xac460004  sw          $a2, 0x4($v0)
    ctx->pc = 0x18a72cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 6));
    // 0x18a730: 0xdfa30120  ld          $v1, 0x120($sp)
    ctx->pc = 0x18a730u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 29), 288)));
    // 0x18a734: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x18a734u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x18a738: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x18a738u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x18a73c: 0xfc430010  sd          $v1, 0x10($v0)
    ctx->pc = 0x18a73cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 16), GPR_U64(ctx, 3));
    // 0x18a740: 0x8fa301a0  lw          $v1, 0x1A0($sp)
    ctx->pc = 0x18a740u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 416)));
    // 0x18a744: 0xac430018  sw          $v1, 0x18($v0)
    ctx->pc = 0x18a744u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 3));
    // 0x18a748: 0xc0631fc  jal         func_18C7F0
    ctx->pc = 0x18A748u;
    SET_GPR_U32(ctx, 31, 0x18A750u);
    ctx->pc = 0x18A74Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18A748u;
            // 0x18a74c: 0xac40001c  sw          $zero, 0x1C($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C7F0u;
    if (runtime->hasFunction(0x18C7F0u)) {
        auto targetFn = runtime->lookupFunction(0x18C7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A750u; }
        if (ctx->pc != 0x18A750u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7F0_0x18c7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A750u; }
        if (ctx->pc != 0x18A750u) { return; }
    }
    ctx->pc = 0x18A750u;
label_18a750:
    // 0x18a750: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x18a750u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a754: 0x3c030010  lui         $v1, 0x10
    ctx->pc = 0x18a754u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16 << 16));
    // 0x18a758: 0x8fa20150  lw          $v0, 0x150($sp)
    ctx->pc = 0x18a758u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 336)));
    // 0x18a75c: 0x2b42023  subu        $a0, $s5, $s4
    ctx->pc = 0x18a75cu;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 20)));
    // 0x18a760: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x18a760u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x18a764: 0x43102b  sltu        $v0, $v0, $v1
    ctx->pc = 0x18a764u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x18a768: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x18A768u;
    {
        const bool branch_taken_0x18a768 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18A76Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A768u;
            // 0x18a76c: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a768) {
            ctx->pc = 0x18A794u;
            goto label_18a794;
        }
    }
    ctx->pc = 0x18A770u;
    // 0x18a770: 0x41102  srl         $v0, $a0, 4
    ctx->pc = 0x18a770u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 4));
    // 0x18a774: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x18a774u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a778: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x18a778u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a77c: 0x2445ffff  addiu       $a1, $v0, -0x1
    ctx->pc = 0x18a77cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x18a780: 0xc06317c  jal         func_18C5F0
    ctx->pc = 0x18A780u;
    SET_GPR_U32(ctx, 31, 0x18A788u);
    ctx->pc = 0x18A784u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18A780u;
            // 0x18a784: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C5F0u;
    if (runtime->hasFunction(0x18C5F0u)) {
        auto targetFn = runtime->lookupFunction(0x18C5F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A788u; }
        if (ctx->pc != 0x18A788u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C5F0_0x18c5f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A788u; }
        if (ctx->pc != 0x18A788u) { return; }
    }
    ctx->pc = 0x18A788u;
label_18a788:
    // 0x18a788: 0x2a0a02d  daddu       $s4, $s5, $zero
    ctx->pc = 0x18a788u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a78c: 0x26b50010  addiu       $s5, $s5, 0x10
    ctx->pc = 0x18a78cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 16));
    // 0x18a790: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x18a790u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18a794:
    // 0x18a794: 0x8fa20200  lw          $v0, 0x200($sp)
    ctx->pc = 0x18a794u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 512)));
    // 0x18a798: 0x2a0b82d  daddu       $s7, $s5, $zero
    ctx->pc = 0x18a798u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a79c: 0x26b50030  addiu       $s5, $s5, 0x30
    ctx->pc = 0x18a79cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 48));
    // 0x18a7a0: 0xafa20210  sw          $v0, 0x210($sp)
    ctx->pc = 0x18a7a0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 528), GPR_U32(ctx, 2));
    // 0x18a7a4: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x18a7a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x18a7a8: 0xafa201f0  sw          $v0, 0x1F0($sp)
    ctx->pc = 0x18a7a8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 496), GPR_U32(ctx, 2));
label_18a7ac:
    // 0x18a7ac: 0x8fa201c0  lw          $v0, 0x1C0($sp)
    ctx->pc = 0x18a7acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 448)));
    // 0x18a7b0: 0xafa00250  sw          $zero, 0x250($sp)
    ctx->pc = 0x18a7b0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 592), GPR_U32(ctx, 0));
    // 0x18a7b4: 0x30423fff  andi        $v0, $v0, 0x3FFF
    ctx->pc = 0x18a7b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)16383);
    // 0x18a7b8: 0x1000023f  b           . + 4 + (0x23F << 2)
    ctx->pc = 0x18A7B8u;
    {
        const bool branch_taken_0x18a7b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18A7BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A7B8u;
            // 0x18a7bc: 0xafa200b0  sw          $v0, 0xB0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 176), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a7b8) {
            ctx->pc = 0x18B0B8u;
            goto label_18b0b8;
        }
    }
    ctx->pc = 0x18A7C0u;
label_18a7c0:
    // 0x18a7c0: 0x8fa20180  lw          $v0, 0x180($sp)
    ctx->pc = 0x18a7c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 384)));
    // 0x18a7c4: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x18a7c4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x18a7c8: 0x2463fd60  addiu       $v1, $v1, -0x2A0
    ctx->pc = 0x18a7c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294966624));
    // 0x18a7cc: 0x8c450018  lw          $a1, 0x18($v0)
    ctx->pc = 0x18a7ccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x18a7d0: 0x8c440020  lw          $a0, 0x20($v0)
    ctx->pc = 0x18a7d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x18a7d4: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x18a7d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x18a7d8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x18a7d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x18a7dc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x18a7dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18a7e0: 0x8fa301f0  lw          $v1, 0x1F0($sp)
    ctx->pc = 0x18a7e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 496)));
    // 0x18a7e4: 0xafa201e0  sw          $v0, 0x1E0($sp)
    ctx->pc = 0x18a7e4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 480), GPR_U32(ctx, 2));
    // 0x18a7e8: 0x8fa201e0  lw          $v0, 0x1E0($sp)
    ctx->pc = 0x18a7e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 480)));
    // 0x18a7ec: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x18a7ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x18a7f0: 0x44102b  sltu        $v0, $v0, $a0
    ctx->pc = 0x18a7f0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x18a7f4: 0x1440003e  bnez        $v0, . + 4 + (0x3E << 2)
    ctx->pc = 0x18A7F4u;
    {
        const bool branch_taken_0x18a7f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18A7F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A7F4u;
            // 0x18a7f8: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a7f4) {
            ctx->pc = 0x18A8F0u;
            goto label_18a8f0;
        }
    }
    ctx->pc = 0x18A7FCu;
    // 0x18a7fc: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x18a7fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a800: 0x22902  srl         $a1, $v0, 4
    ctx->pc = 0x18a800u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
    // 0x18a804: 0xc063204  jal         func_18C810
    ctx->pc = 0x18A804u;
    SET_GPR_U32(ctx, 31, 0x18A80Cu);
    ctx->pc = 0x18A808u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18A804u;
            // 0x18a808: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C810u;
    if (runtime->hasFunction(0x18C810u)) {
        auto targetFn = runtime->lookupFunction(0x18C810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A80Cu; }
        if (ctx->pc != 0x18A80Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C810_0x18c810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A80Cu; }
        if (ctx->pc != 0x18A80Cu) { return; }
    }
    ctx->pc = 0x18A80Cu;
label_18a80c:
    // 0x18a80c: 0x8fa30210  lw          $v1, 0x210($sp)
    ctx->pc = 0x18a80cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 528)));
    // 0x18a810: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x18a810u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18a814: 0x10640007  beq         $v1, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x18A814u;
    {
        const bool branch_taken_0x18a814 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x18a814) {
            ctx->pc = 0x18A834u;
            goto label_18a834;
        }
    }
    ctx->pc = 0x18A81Cu;
    // 0x18a81c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x18A81Cu;
    {
        const bool branch_taken_0x18a81c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x18a81c) {
            ctx->pc = 0x18A82Cu;
            goto label_18a82c;
        }
    }
    ctx->pc = 0x18A824u;
    // 0x18a824: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x18A824u;
    {
        const bool branch_taken_0x18a824 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18A828u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A824u;
            // 0x18a828: 0x8fa30140  lw          $v1, 0x140($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 320)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a824) {
            ctx->pc = 0x18A840u;
            goto label_18a840;
        }
    }
    ctx->pc = 0x18A82Cu;
label_18a82c:
    // 0x18a82c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x18A82Cu;
    {
        const bool branch_taken_0x18a82c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18A830u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A82Cu;
            // 0x18a830: 0xac440000  sw          $a0, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a82c) {
            ctx->pc = 0x18A83Cu;
            goto label_18a83c;
        }
    }
    ctx->pc = 0x18A834u;
label_18a834:
    // 0x18a834: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x18a834u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x18a838: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x18a838u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
label_18a83c:
    // 0x18a83c: 0x8fa30140  lw          $v1, 0x140($sp)
    ctx->pc = 0x18a83cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 320)));
label_18a840:
    // 0x18a840: 0x26650002  addiu       $a1, $s3, 0x2
    ctx->pc = 0x18a840u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
    // 0x18a844: 0x13303c  dsll32      $a2, $s3, 0
    ctx->pc = 0x18a844u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 19) << (32 + 0));
    // 0x18a848: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x18a848u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a84c: 0x6303f  dsra32      $a2, $a2, 0
    ctx->pc = 0x18a84cu;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 0));
    // 0x18a850: 0x653818  mult        $a3, $v1, $a1
    ctx->pc = 0x18a850u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 7, (int32_t)result); }
    // 0x18a854: 0x24054000  addiu       $a1, $zero, 0x4000
    ctx->pc = 0x18a854u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x18a858: 0x34038000  ori         $v1, $zero, 0x8000
    ctx->pc = 0x18a858u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x18a85c: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x18a85cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x18a860: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x18a860u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x18a864: 0xc32825  or          $a1, $a2, $v1
    ctx->pc = 0x18a864u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x18a868: 0x71902  srl         $v1, $a3, 4
    ctx->pc = 0x18a868u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 7), 4));
    // 0x18a86c: 0x24660001  addiu       $a2, $v1, 0x1
    ctx->pc = 0x18a86cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x18a870: 0xdfa30130  ld          $v1, 0x130($sp)
    ctx->pc = 0x18a870u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x18a874: 0xa32825  or          $a1, $a1, $v1
    ctx->pc = 0x18a874u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x18a878: 0xac460004  sw          $a2, 0x4($v0)
    ctx->pc = 0x18a878u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 6));
    // 0x18a87c: 0xdfa30120  ld          $v1, 0x120($sp)
    ctx->pc = 0x18a87cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 29), 288)));
    // 0x18a880: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x18a880u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x18a884: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x18a884u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x18a888: 0xfc430010  sd          $v1, 0x10($v0)
    ctx->pc = 0x18a888u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 16), GPR_U64(ctx, 3));
    // 0x18a88c: 0x8fa301a0  lw          $v1, 0x1A0($sp)
    ctx->pc = 0x18a88cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 416)));
    // 0x18a890: 0xac430018  sw          $v1, 0x18($v0)
    ctx->pc = 0x18a890u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 3));
    // 0x18a894: 0xc0631fc  jal         func_18C7F0
    ctx->pc = 0x18A894u;
    SET_GPR_U32(ctx, 31, 0x18A89Cu);
    ctx->pc = 0x18A898u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18A894u;
            // 0x18a898: 0xac40001c  sw          $zero, 0x1C($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C7F0u;
    if (runtime->hasFunction(0x18C7F0u)) {
        auto targetFn = runtime->lookupFunction(0x18C7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A89Cu; }
        if (ctx->pc != 0x18A89Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7F0_0x18c7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A89Cu; }
        if (ctx->pc != 0x18A89Cu) { return; }
    }
    ctx->pc = 0x18A89Cu;
label_18a89c:
    // 0x18a89c: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x18a89cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a8a0: 0x3c030010  lui         $v1, 0x10
    ctx->pc = 0x18a8a0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16 << 16));
    // 0x18a8a4: 0x8fa20150  lw          $v0, 0x150($sp)
    ctx->pc = 0x18a8a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 336)));
    // 0x18a8a8: 0x2b42023  subu        $a0, $s5, $s4
    ctx->pc = 0x18a8a8u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 20)));
    // 0x18a8ac: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x18a8acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x18a8b0: 0x43102b  sltu        $v0, $v0, $v1
    ctx->pc = 0x18a8b0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x18a8b4: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x18A8B4u;
    {
        const bool branch_taken_0x18a8b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18A8B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A8B4u;
            // 0x18a8b8: 0x2a0b82d  daddu       $s7, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a8b4) {
            ctx->pc = 0x18A8E0u;
            goto label_18a8e0;
        }
    }
    ctx->pc = 0x18A8BCu;
    // 0x18a8bc: 0x41102  srl         $v0, $a0, 4
    ctx->pc = 0x18a8bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 4));
    // 0x18a8c0: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x18a8c0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a8c4: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x18a8c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a8c8: 0x2445ffff  addiu       $a1, $v0, -0x1
    ctx->pc = 0x18a8c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x18a8cc: 0xc06317c  jal         func_18C5F0
    ctx->pc = 0x18A8CCu;
    SET_GPR_U32(ctx, 31, 0x18A8D4u);
    ctx->pc = 0x18A8D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18A8CCu;
            // 0x18a8d0: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C5F0u;
    if (runtime->hasFunction(0x18C5F0u)) {
        auto targetFn = runtime->lookupFunction(0x18C5F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A8D4u; }
        if (ctx->pc != 0x18A8D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C5F0_0x18c5f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18A8D4u; }
        if (ctx->pc != 0x18A8D4u) { return; }
    }
    ctx->pc = 0x18A8D4u;
label_18a8d4:
    // 0x18a8d4: 0x2a0a02d  daddu       $s4, $s5, $zero
    ctx->pc = 0x18a8d4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18a8d8: 0x26b50010  addiu       $s5, $s5, 0x10
    ctx->pc = 0x18a8d8u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 16));
    // 0x18a8dc: 0x2a0b82d  daddu       $s7, $s5, $zero
    ctx->pc = 0x18a8dcu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
label_18a8e0:
    // 0x18a8e0: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x18a8e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x18a8e4: 0xafa201f0  sw          $v0, 0x1F0($sp)
    ctx->pc = 0x18a8e4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 496), GPR_U32(ctx, 2));
    // 0x18a8e8: 0x26b50030  addiu       $s5, $s5, 0x30
    ctx->pc = 0x18a8e8u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 48));
    // 0x18a8ec: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x18a8ecu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18a8f0:
    // 0x18a8f0: 0x8fa301f0  lw          $v1, 0x1F0($sp)
    ctx->pc = 0x18a8f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 496)));
    // 0x18a8f4: 0x8fa201e0  lw          $v0, 0x1E0($sp)
    ctx->pc = 0x18a8f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 480)));
    // 0x18a8f8: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x18a8f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x18a8fc: 0x8fa2026c  lw          $v0, 0x26C($sp)
    ctx->pc = 0x18a8fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 620)));
    // 0x18a900: 0xafa301f0  sw          $v1, 0x1F0($sp)
    ctx->pc = 0x18a900u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 496), GPR_U32(ctx, 3));
    // 0x18a904: 0x8c43000c  lw          $v1, 0xC($v0)
    ctx->pc = 0x18a904u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x18a908: 0x24020135  addiu       $v0, $zero, 0x135
    ctx->pc = 0x18a908u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 309));
    // 0x18a90c: 0x106200fe  beq         $v1, $v0, . + 4 + (0xFE << 2)
    ctx->pc = 0x18A90Cu;
    {
        const bool branch_taken_0x18a90c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x18A910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A90Cu;
            // 0x18a910: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a90c) {
            ctx->pc = 0x18AD08u;
            goto label_18ad08;
        }
    }
    ctx->pc = 0x18A914u;
    // 0x18a914: 0x24020035  addiu       $v0, $zero, 0x35
    ctx->pc = 0x18a914u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 53));
    // 0x18a918: 0x10620081  beq         $v1, $v0, . + 4 + (0x81 << 2)
    ctx->pc = 0x18A918u;
    {
        const bool branch_taken_0x18a918 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x18A91Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A918u;
            // 0x18a91c: 0x24020025  addiu       $v0, $zero, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 37));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a918) {
            ctx->pc = 0x18AB20u;
            goto label_18ab20;
        }
    }
    ctx->pc = 0x18A920u;
    // 0x18a920: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18A920u;
    {
        const bool branch_taken_0x18a920 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x18a920) {
            ctx->pc = 0x18A930u;
            goto label_18a930;
        }
    }
    ctx->pc = 0x18A928u;
    // 0x18a928: 0x100001de  b           . + 4 + (0x1DE << 2)
    ctx->pc = 0x18A928u;
    {
        const bool branch_taken_0x18a928 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18A92Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A928u;
            // 0x18a92c: 0x8fa20160  lw          $v0, 0x160($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 352)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a928) {
            ctx->pc = 0x18B0A4u;
            goto label_18b0a4;
        }
    }
    ctx->pc = 0x18A930u;
label_18a930:
    // 0x18a930: 0x8fa2026c  lw          $v0, 0x26C($sp)
    ctx->pc = 0x18a930u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 620)));
    // 0x18a934: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x18a934u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18a938: 0x30421000  andi        $v0, $v0, 0x1000
    ctx->pc = 0x18a938u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4096);
    // 0x18a93c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x18A93Cu;
    {
        const bool branch_taken_0x18a93c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18a93c) {
            ctx->pc = 0x18A968u;
            goto label_18a968;
        }
    }
    ctx->pc = 0x18A944u;
    // 0x18a944: 0x8fa2026c  lw          $v0, 0x26C($sp)
    ctx->pc = 0x18a944u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 620)));
    // 0x18a948: 0x96440000  lhu         $a0, 0x0($s2)
    ctx->pc = 0x18a948u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18a94c: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x18a94cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x18a950: 0x418c0  sll         $v1, $a0, 3
    ctx->pc = 0x18a950u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x18a954: 0x26520002  addiu       $s2, $s2, 0x2
    ctx->pc = 0x18a954u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
    // 0x18a958: 0x641823  subu        $v1, $v1, $a0
    ctx->pc = 0x18a958u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x18a95c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x18a95cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18a960: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x18A960u;
    {
        const bool branch_taken_0x18a960 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18A964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A960u;
            // 0x18a964: 0x43b021  addu        $s6, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a960) {
            ctx->pc = 0x18A96Cu;
            goto label_18a96c;
        }
    }
    ctx->pc = 0x18A968u;
label_18a968:
    // 0x18a968: 0x26d6001c  addiu       $s6, $s6, 0x1C
    ctx->pc = 0x18a968u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 28));
label_18a96c:
    // 0x18a96c: 0x8fa20110  lw          $v0, 0x110($sp)
    ctx->pc = 0x18a96cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 272)));
    // 0x18a970: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x18A970u;
    {
        const bool branch_taken_0x18a970 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18a970) {
            ctx->pc = 0x18A9B0u;
            goto label_18a9b0;
        }
    }
    ctx->pc = 0x18A978u;
    // 0x18a978: 0xc6c00000  lwc1        $f0, 0x0($s6)
    ctx->pc = 0x18a978u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 22), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18a97c: 0xe6a00000  swc1        $f0, 0x0($s5)
    ctx->pc = 0x18a97cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 0), bits); }
    // 0x18a980: 0xc6c00004  lwc1        $f0, 0x4($s6)
    ctx->pc = 0x18a980u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 22), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18a984: 0xe6a00004  swc1        $f0, 0x4($s5)
    ctx->pc = 0x18a984u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 4), bits); }
    // 0x18a988: 0xc6c00008  lwc1        $f0, 0x8($s6)
    ctx->pc = 0x18a988u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 22), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18a98c: 0xe6a00008  swc1        $f0, 0x8($s5)
    ctx->pc = 0x18a98cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 8), bits); }
    // 0x18a990: 0x8fa20250  lw          $v0, 0x250($sp)
    ctx->pc = 0x18a990u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 592)));
    // 0x18a994: 0x28410002  slti        $at, $v0, 0x2
    ctx->pc = 0x18a994u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x18a998: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x18A998u;
    {
        const bool branch_taken_0x18a998 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x18A99Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A998u;
            // 0x18a99c: 0x34028000  ori         $v0, $zero, 0x8000 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a998) {
            ctx->pc = 0x18A9A8u;
            goto label_18a9a8;
        }
    }
    ctx->pc = 0x18A9A0u;
    // 0x18a9a0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x18A9A0u;
    {
        const bool branch_taken_0x18a9a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18A9A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A9A0u;
            // 0x18a9a4: 0xaea2000c  sw          $v0, 0xC($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a9a0) {
            ctx->pc = 0x18A9ACu;
            goto label_18a9ac;
        }
    }
    ctx->pc = 0x18A9A8u;
label_18a9a8:
    // 0x18a9a8: 0xaea0000c  sw          $zero, 0xC($s5)
    ctx->pc = 0x18a9a8u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 0));
label_18a9ac:
    // 0x18a9ac: 0x26b50010  addiu       $s5, $s5, 0x10
    ctx->pc = 0x18a9acu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 16));
label_18a9b0:
    // 0x18a9b0: 0x8fa20100  lw          $v0, 0x100($sp)
    ctx->pc = 0x18a9b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 256)));
    // 0x18a9b4: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x18A9B4u;
    {
        const bool branch_taken_0x18a9b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18a9b4) {
            ctx->pc = 0x18A9F4u;
            goto label_18a9f4;
        }
    }
    ctx->pc = 0x18A9BCu;
    // 0x18a9bc: 0xc6c0000c  lwc1        $f0, 0xC($s6)
    ctx->pc = 0x18a9bcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 22), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18a9c0: 0xe6a00000  swc1        $f0, 0x0($s5)
    ctx->pc = 0x18a9c0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 0), bits); }
    // 0x18a9c4: 0xc6c00010  lwc1        $f0, 0x10($s6)
    ctx->pc = 0x18a9c4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 22), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18a9c8: 0xe6a00004  swc1        $f0, 0x4($s5)
    ctx->pc = 0x18a9c8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 4), bits); }
    // 0x18a9cc: 0xc6c00014  lwc1        $f0, 0x14($s6)
    ctx->pc = 0x18a9ccu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 22), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18a9d0: 0xe6a00008  swc1        $f0, 0x8($s5)
    ctx->pc = 0x18a9d0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 8), bits); }
    // 0x18a9d4: 0x8fa20160  lw          $v0, 0x160($sp)
    ctx->pc = 0x18a9d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 352)));
    // 0x18a9d8: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18A9D8u;
    {
        const bool branch_taken_0x18a9d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18A9DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A9D8u;
            // 0x18a9dc: 0x3c02bf80  lui         $v0, 0xBF80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a9d8) {
            ctx->pc = 0x18A9ECu;
            goto label_18a9ec;
        }
    }
    ctx->pc = 0x18A9E0u;
    // 0x18a9e0: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x18a9e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x18a9e4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x18A9E4u;
    {
        const bool branch_taken_0x18a9e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18A9E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18A9E4u;
            // 0x18a9e8: 0xaea2000c  sw          $v0, 0xC($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18a9e4) {
            ctx->pc = 0x18A9F0u;
            goto label_18a9f0;
        }
    }
    ctx->pc = 0x18A9ECu;
label_18a9ec:
    // 0x18a9ec: 0xaea2000c  sw          $v0, 0xC($s5)
    ctx->pc = 0x18a9ecu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 2));
label_18a9f0:
    // 0x18a9f0: 0x26b50010  addiu       $s5, $s5, 0x10
    ctx->pc = 0x18a9f0u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 16));
label_18a9f4:
    // 0x18a9f4: 0x8fa200f0  lw          $v0, 0xF0($sp)
    ctx->pc = 0x18a9f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 240)));
    // 0x18a9f8: 0x104001a9  beqz        $v0, . + 4 + (0x1A9 << 2)
    ctx->pc = 0x18A9F8u;
    {
        const bool branch_taken_0x18a9f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18a9f8) {
            ctx->pc = 0x18B0A0u;
            goto label_18b0a0;
        }
    }
    ctx->pc = 0x18AA00u;
    // 0x18aa00: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x18aa00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x18aa04: 0x30420f00  andi        $v0, $v0, 0xF00
    ctx->pc = 0x18aa04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3840);
    // 0x18aa08: 0x1440002d  bnez        $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x18AA08u;
    {
        const bool branch_taken_0x18aa08 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18aa08) {
            ctx->pc = 0x18AAC0u;
            goto label_18aac0;
        }
    }
    ctx->pc = 0x18AA10u;
    // 0x18aa10: 0x8ec20018  lw          $v0, 0x18($s6)
    ctx->pc = 0x18aa10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 24)));
    // 0x18aa14: 0x21402  srl         $v0, $v0, 16
    ctx->pc = 0x18aa14u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x18aa18: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x18aa18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x18aa1c: 0x4400004  bltz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18AA1Cu;
    {
        const bool branch_taken_0x18aa1c = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x18AA20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18AA1Cu;
            // 0x18aa20: 0x21842  srl         $v1, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18aa1c) {
            ctx->pc = 0x18AA30u;
            goto label_18aa30;
        }
    }
    ctx->pc = 0x18AA24u;
    // 0x18aa24: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18aa24u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18aa28: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x18AA28u;
    {
        const bool branch_taken_0x18aa28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18AA2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18AA28u;
            // 0x18aa2c: 0x46800020  cvt.s.w     $f0, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18aa28) {
            ctx->pc = 0x18AA48u;
            goto label_18aa48;
        }
    }
    ctx->pc = 0x18AA30u;
label_18aa30:
    // 0x18aa30: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x18aa30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x18aa34: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x18aa34u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x18aa38: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x18aa38u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18aa3c: 0x0  nop
    ctx->pc = 0x18aa3cu;
    // NOP
    // 0x18aa40: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18aa40u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18aa44: 0x46000000  add.s       $f0, $f0, $f0
    ctx->pc = 0x18aa44u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[0]);
label_18aa48:
    // 0x18aa48: 0xe6a00000  swc1        $f0, 0x0($s5)
    ctx->pc = 0x18aa48u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 0), bits); }
    // 0x18aa4c: 0x8ec20018  lw          $v0, 0x18($s6)
    ctx->pc = 0x18aa4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 24)));
    // 0x18aa50: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x18aa50u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x18aa54: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x18aa54u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x18aa58: 0x4400004  bltz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18AA58u;
    {
        const bool branch_taken_0x18aa58 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x18AA5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18AA58u;
            // 0x18aa5c: 0x21842  srl         $v1, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18aa58) {
            ctx->pc = 0x18AA6Cu;
            goto label_18aa6c;
        }
    }
    ctx->pc = 0x18AA60u;
    // 0x18aa60: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18aa60u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18aa64: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x18AA64u;
    {
        const bool branch_taken_0x18aa64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18AA68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18AA64u;
            // 0x18aa68: 0x46800020  cvt.s.w     $f0, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18aa64) {
            ctx->pc = 0x18AA84u;
            goto label_18aa84;
        }
    }
    ctx->pc = 0x18AA6Cu;
label_18aa6c:
    // 0x18aa6c: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x18aa6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x18aa70: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x18aa70u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x18aa74: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x18aa74u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18aa78: 0x0  nop
    ctx->pc = 0x18aa78u;
    // NOP
    // 0x18aa7c: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18aa7cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18aa80: 0x46000000  add.s       $f0, $f0, $f0
    ctx->pc = 0x18aa80u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[0]);
label_18aa84:
    // 0x18aa84: 0xe6a00004  swc1        $f0, 0x4($s5)
    ctx->pc = 0x18aa84u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 4), bits); }
    // 0x18aa88: 0x92c20018  lbu         $v0, 0x18($s6)
    ctx->pc = 0x18aa88u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 22), 24)));
    // 0x18aa8c: 0x4400004  bltz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18AA8Cu;
    {
        const bool branch_taken_0x18aa8c = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x18AA90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18AA8Cu;
            // 0x18aa90: 0x21842  srl         $v1, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18aa8c) {
            ctx->pc = 0x18AAA0u;
            goto label_18aaa0;
        }
    }
    ctx->pc = 0x18AA94u;
    // 0x18aa94: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18aa94u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18aa98: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x18AA98u;
    {
        const bool branch_taken_0x18aa98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18AA9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18AA98u;
            // 0x18aa9c: 0x46800020  cvt.s.w     $f0, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18aa98) {
            ctx->pc = 0x18AAB8u;
            goto label_18aab8;
        }
    }
    ctx->pc = 0x18AAA0u;
label_18aaa0:
    // 0x18aaa0: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x18aaa0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x18aaa4: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x18aaa4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x18aaa8: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x18aaa8u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18aaac: 0x0  nop
    ctx->pc = 0x18aaacu;
    // NOP
    // 0x18aab0: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18aab0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18aab4: 0x46000000  add.s       $f0, $f0, $f0
    ctx->pc = 0x18aab4u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[0]);
label_18aab8:
    // 0x18aab8: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x18AAB8u;
    {
        const bool branch_taken_0x18aab8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18AABCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18AAB8u;
            // 0x18aabc: 0xe6a00008  swc1        $f0, 0x8($s5) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 8), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18aab8) {
            ctx->pc = 0x18AB00u;
            goto label_18ab00;
        }
    }
    ctx->pc = 0x18AAC0u;
label_18aac0:
    // 0x18aac0: 0x8ec20018  lw          $v0, 0x18($s6)
    ctx->pc = 0x18aac0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 24)));
    // 0x18aac4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x18aac4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18aac8: 0x21402  srl         $v0, $v0, 16
    ctx->pc = 0x18aac8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x18aacc: 0xc062cb0  jal         func_18B2C0
    ctx->pc = 0x18AACCu;
    SET_GPR_U32(ctx, 31, 0x18AAD4u);
    ctx->pc = 0x18AAD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18AACCu;
            // 0x18aad0: 0x304400ff  andi        $a0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B2C0u;
    if (runtime->hasFunction(0x18B2C0u)) {
        auto targetFn = runtime->lookupFunction(0x18B2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AAD4u; }
        if (ctx->pc != 0x18AAD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B2C0_0x18b2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AAD4u; }
        if (ctx->pc != 0x18AAD4u) { return; }
    }
    ctx->pc = 0x18AAD4u;
label_18aad4:
    // 0x18aad4: 0xe6a00000  swc1        $f0, 0x0($s5)
    ctx->pc = 0x18aad4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 0), bits); }
    // 0x18aad8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x18aad8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18aadc: 0x8ec20018  lw          $v0, 0x18($s6)
    ctx->pc = 0x18aadcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 24)));
    // 0x18aae0: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x18aae0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x18aae4: 0xc062cb0  jal         func_18B2C0
    ctx->pc = 0x18AAE4u;
    SET_GPR_U32(ctx, 31, 0x18AAECu);
    ctx->pc = 0x18AAE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18AAE4u;
            // 0x18aae8: 0x304400ff  andi        $a0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B2C0u;
    if (runtime->hasFunction(0x18B2C0u)) {
        auto targetFn = runtime->lookupFunction(0x18B2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AAECu; }
        if (ctx->pc != 0x18AAECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B2C0_0x18b2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AAECu; }
        if (ctx->pc != 0x18AAECu) { return; }
    }
    ctx->pc = 0x18AAECu;
label_18aaec:
    // 0x18aaec: 0xe6a00004  swc1        $f0, 0x4($s5)
    ctx->pc = 0x18aaecu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 4), bits); }
    // 0x18aaf0: 0x92c40018  lbu         $a0, 0x18($s6)
    ctx->pc = 0x18aaf0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 22), 24)));
    // 0x18aaf4: 0xc062cb0  jal         func_18B2C0
    ctx->pc = 0x18AAF4u;
    SET_GPR_U32(ctx, 31, 0x18AAFCu);
    ctx->pc = 0x18AAF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18AAF4u;
            // 0x18aaf8: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B2C0u;
    if (runtime->hasFunction(0x18B2C0u)) {
        auto targetFn = runtime->lookupFunction(0x18B2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AAFCu; }
        if (ctx->pc != 0x18AAFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B2C0_0x18b2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AAFCu; }
        if (ctx->pc != 0x18AAFCu) { return; }
    }
    ctx->pc = 0x18AAFCu;
label_18aafc:
    // 0x18aafc: 0xe6a00008  swc1        $f0, 0x8($s5)
    ctx->pc = 0x18aafcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 8), bits); }
label_18ab00:
    // 0x18ab00: 0x8ec20018  lw          $v0, 0x18($s6)
    ctx->pc = 0x18ab00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 24)));
    // 0x18ab04: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x18ab04u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ab08: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x18ab08u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x18ab0c: 0xc062cb0  jal         func_18B2C0
    ctx->pc = 0x18AB0Cu;
    SET_GPR_U32(ctx, 31, 0x18AB14u);
    ctx->pc = 0x18AB10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18AB0Cu;
            // 0x18ab10: 0x304400ff  andi        $a0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B2C0u;
    if (runtime->hasFunction(0x18B2C0u)) {
        auto targetFn = runtime->lookupFunction(0x18B2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AB14u; }
        if (ctx->pc != 0x18AB14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B2C0_0x18b2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AB14u; }
        if (ctx->pc != 0x18AB14u) { return; }
    }
    ctx->pc = 0x18AB14u;
label_18ab14:
    // 0x18ab14: 0xe6a0000c  swc1        $f0, 0xC($s5)
    ctx->pc = 0x18ab14u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 12), bits); }
    // 0x18ab18: 0x10000161  b           . + 4 + (0x161 << 2)
    ctx->pc = 0x18AB18u;
    {
        const bool branch_taken_0x18ab18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18AB1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18AB18u;
            // 0x18ab1c: 0x26b50010  addiu       $s5, $s5, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ab18) {
            ctx->pc = 0x18B0A0u;
            goto label_18b0a0;
        }
    }
    ctx->pc = 0x18AB20u;
label_18ab20:
    // 0x18ab20: 0x8fa2026c  lw          $v0, 0x26C($sp)
    ctx->pc = 0x18ab20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 620)));
    // 0x18ab24: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x18ab24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18ab28: 0x30421000  andi        $v0, $v0, 0x1000
    ctx->pc = 0x18ab28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4096);
    // 0x18ab2c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x18AB2Cu;
    {
        const bool branch_taken_0x18ab2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18ab2c) {
            ctx->pc = 0x18AB58u;
            goto label_18ab58;
        }
    }
    ctx->pc = 0x18AB34u;
    // 0x18ab34: 0x8fa2026c  lw          $v0, 0x26C($sp)
    ctx->pc = 0x18ab34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 620)));
    // 0x18ab38: 0x96440000  lhu         $a0, 0x0($s2)
    ctx->pc = 0x18ab38u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18ab3c: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x18ab3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x18ab40: 0x418c0  sll         $v1, $a0, 3
    ctx->pc = 0x18ab40u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x18ab44: 0x26520002  addiu       $s2, $s2, 0x2
    ctx->pc = 0x18ab44u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
    // 0x18ab48: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x18ab48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x18ab4c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x18ab4cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18ab50: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x18AB50u;
    {
        const bool branch_taken_0x18ab50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18AB54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18AB50u;
            // 0x18ab54: 0x438821  addu        $s1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ab50) {
            ctx->pc = 0x18AB5Cu;
            goto label_18ab5c;
        }
    }
    ctx->pc = 0x18AB58u;
label_18ab58:
    // 0x18ab58: 0x26310024  addiu       $s1, $s1, 0x24
    ctx->pc = 0x18ab58u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 36));
label_18ab5c:
    // 0x18ab5c: 0x8fa20110  lw          $v0, 0x110($sp)
    ctx->pc = 0x18ab5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 272)));
    // 0x18ab60: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x18AB60u;
    {
        const bool branch_taken_0x18ab60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18ab60) {
            ctx->pc = 0x18ABA0u;
            goto label_18aba0;
        }
    }
    ctx->pc = 0x18AB68u;
    // 0x18ab68: 0xc6200000  lwc1        $f0, 0x0($s1)
    ctx->pc = 0x18ab68u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18ab6c: 0xe6a00000  swc1        $f0, 0x0($s5)
    ctx->pc = 0x18ab6cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 0), bits); }
    // 0x18ab70: 0xc6200004  lwc1        $f0, 0x4($s1)
    ctx->pc = 0x18ab70u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18ab74: 0xe6a00004  swc1        $f0, 0x4($s5)
    ctx->pc = 0x18ab74u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 4), bits); }
    // 0x18ab78: 0xc6200008  lwc1        $f0, 0x8($s1)
    ctx->pc = 0x18ab78u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18ab7c: 0xe6a00008  swc1        $f0, 0x8($s5)
    ctx->pc = 0x18ab7cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 8), bits); }
    // 0x18ab80: 0x8fa20250  lw          $v0, 0x250($sp)
    ctx->pc = 0x18ab80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 592)));
    // 0x18ab84: 0x28410002  slti        $at, $v0, 0x2
    ctx->pc = 0x18ab84u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x18ab88: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x18AB88u;
    {
        const bool branch_taken_0x18ab88 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x18AB8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18AB88u;
            // 0x18ab8c: 0x34028000  ori         $v0, $zero, 0x8000 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ab88) {
            ctx->pc = 0x18AB98u;
            goto label_18ab98;
        }
    }
    ctx->pc = 0x18AB90u;
    // 0x18ab90: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x18AB90u;
    {
        const bool branch_taken_0x18ab90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18AB94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18AB90u;
            // 0x18ab94: 0xaea2000c  sw          $v0, 0xC($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ab90) {
            ctx->pc = 0x18AB9Cu;
            goto label_18ab9c;
        }
    }
    ctx->pc = 0x18AB98u;
label_18ab98:
    // 0x18ab98: 0xaea0000c  sw          $zero, 0xC($s5)
    ctx->pc = 0x18ab98u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 0));
label_18ab9c:
    // 0x18ab9c: 0x26b50010  addiu       $s5, $s5, 0x10
    ctx->pc = 0x18ab9cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 16));
label_18aba0:
    // 0x18aba0: 0x8fa20100  lw          $v0, 0x100($sp)
    ctx->pc = 0x18aba0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 256)));
    // 0x18aba4: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x18ABA4u;
    {
        const bool branch_taken_0x18aba4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18aba4) {
            ctx->pc = 0x18ABE4u;
            goto label_18abe4;
        }
    }
    ctx->pc = 0x18ABACu;
    // 0x18abac: 0xc620000c  lwc1        $f0, 0xC($s1)
    ctx->pc = 0x18abacu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18abb0: 0xe6a00000  swc1        $f0, 0x0($s5)
    ctx->pc = 0x18abb0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 0), bits); }
    // 0x18abb4: 0xc6200010  lwc1        $f0, 0x10($s1)
    ctx->pc = 0x18abb4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18abb8: 0xe6a00004  swc1        $f0, 0x4($s5)
    ctx->pc = 0x18abb8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 4), bits); }
    // 0x18abbc: 0xc6200014  lwc1        $f0, 0x14($s1)
    ctx->pc = 0x18abbcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18abc0: 0xe6a00008  swc1        $f0, 0x8($s5)
    ctx->pc = 0x18abc0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 8), bits); }
    // 0x18abc4: 0x8fa20160  lw          $v0, 0x160($sp)
    ctx->pc = 0x18abc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 352)));
    // 0x18abc8: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18ABC8u;
    {
        const bool branch_taken_0x18abc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18ABCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18ABC8u;
            // 0x18abcc: 0x3c02bf80  lui         $v0, 0xBF80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18abc8) {
            ctx->pc = 0x18ABDCu;
            goto label_18abdc;
        }
    }
    ctx->pc = 0x18ABD0u;
    // 0x18abd0: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x18abd0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x18abd4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x18ABD4u;
    {
        const bool branch_taken_0x18abd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18ABD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18ABD4u;
            // 0x18abd8: 0xaea2000c  sw          $v0, 0xC($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18abd4) {
            ctx->pc = 0x18ABE0u;
            goto label_18abe0;
        }
    }
    ctx->pc = 0x18ABDCu;
label_18abdc:
    // 0x18abdc: 0xaea2000c  sw          $v0, 0xC($s5)
    ctx->pc = 0x18abdcu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 2));
label_18abe0:
    // 0x18abe0: 0x26b50010  addiu       $s5, $s5, 0x10
    ctx->pc = 0x18abe0u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 16));
label_18abe4:
    // 0x18abe4: 0x8fa200f0  lw          $v0, 0xF0($sp)
    ctx->pc = 0x18abe4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 240)));
    // 0x18abe8: 0x1040002d  beqz        $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x18ABE8u;
    {
        const bool branch_taken_0x18abe8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18abe8) {
            ctx->pc = 0x18ACA0u;
            goto label_18aca0;
        }
    }
    ctx->pc = 0x18ABF0u;
    // 0x18abf0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x18abf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x18abf4: 0x30420f00  andi        $v0, $v0, 0xF00
    ctx->pc = 0x18abf4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3840);
    // 0x18abf8: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x18ABF8u;
    {
        const bool branch_taken_0x18abf8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18abf8) {
            ctx->pc = 0x18AC44u;
            goto label_18ac44;
        }
    }
    ctx->pc = 0x18AC00u;
    // 0x18ac00: 0x8e220018  lw          $v0, 0x18($s1)
    ctx->pc = 0x18ac00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x18ac04: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x18ac04u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ac08: 0x21402  srl         $v0, $v0, 16
    ctx->pc = 0x18ac08u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x18ac0c: 0xc062cb0  jal         func_18B2C0
    ctx->pc = 0x18AC0Cu;
    SET_GPR_U32(ctx, 31, 0x18AC14u);
    ctx->pc = 0x18AC10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18AC0Cu;
            // 0x18ac10: 0x304400ff  andi        $a0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B2C0u;
    if (runtime->hasFunction(0x18B2C0u)) {
        auto targetFn = runtime->lookupFunction(0x18B2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AC14u; }
        if (ctx->pc != 0x18AC14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B2C0_0x18b2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AC14u; }
        if (ctx->pc != 0x18AC14u) { return; }
    }
    ctx->pc = 0x18AC14u;
label_18ac14:
    // 0x18ac14: 0xe6a00000  swc1        $f0, 0x0($s5)
    ctx->pc = 0x18ac14u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 0), bits); }
    // 0x18ac18: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x18ac18u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ac1c: 0x8e220018  lw          $v0, 0x18($s1)
    ctx->pc = 0x18ac1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x18ac20: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x18ac20u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x18ac24: 0xc062cb0  jal         func_18B2C0
    ctx->pc = 0x18AC24u;
    SET_GPR_U32(ctx, 31, 0x18AC2Cu);
    ctx->pc = 0x18AC28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18AC24u;
            // 0x18ac28: 0x304400ff  andi        $a0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B2C0u;
    if (runtime->hasFunction(0x18B2C0u)) {
        auto targetFn = runtime->lookupFunction(0x18B2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AC2Cu; }
        if (ctx->pc != 0x18AC2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B2C0_0x18b2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AC2Cu; }
        if (ctx->pc != 0x18AC2Cu) { return; }
    }
    ctx->pc = 0x18AC2Cu;
label_18ac2c:
    // 0x18ac2c: 0xe6a00004  swc1        $f0, 0x4($s5)
    ctx->pc = 0x18ac2cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 4), bits); }
    // 0x18ac30: 0x92240018  lbu         $a0, 0x18($s1)
    ctx->pc = 0x18ac30u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x18ac34: 0xc062cb0  jal         func_18B2C0
    ctx->pc = 0x18AC34u;
    SET_GPR_U32(ctx, 31, 0x18AC3Cu);
    ctx->pc = 0x18AC38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18AC34u;
            // 0x18ac38: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B2C0u;
    if (runtime->hasFunction(0x18B2C0u)) {
        auto targetFn = runtime->lookupFunction(0x18B2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AC3Cu; }
        if (ctx->pc != 0x18AC3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B2C0_0x18b2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AC3Cu; }
        if (ctx->pc != 0x18AC3Cu) { return; }
    }
    ctx->pc = 0x18AC3Cu;
label_18ac3c:
    // 0x18ac3c: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x18AC3Cu;
    {
        const bool branch_taken_0x18ac3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18AC40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18AC3Cu;
            // 0x18ac40: 0xe6a00008  swc1        $f0, 0x8($s5) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 8), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ac3c) {
            ctx->pc = 0x18AC84u;
            goto label_18ac84;
        }
    }
    ctx->pc = 0x18AC44u;
label_18ac44:
    // 0x18ac44: 0x8e220018  lw          $v0, 0x18($s1)
    ctx->pc = 0x18ac44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x18ac48: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x18ac48u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18ac4c: 0x21402  srl         $v0, $v0, 16
    ctx->pc = 0x18ac4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x18ac50: 0xc062cb0  jal         func_18B2C0
    ctx->pc = 0x18AC50u;
    SET_GPR_U32(ctx, 31, 0x18AC58u);
    ctx->pc = 0x18AC54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18AC50u;
            // 0x18ac54: 0x304400ff  andi        $a0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B2C0u;
    if (runtime->hasFunction(0x18B2C0u)) {
        auto targetFn = runtime->lookupFunction(0x18B2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AC58u; }
        if (ctx->pc != 0x18AC58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B2C0_0x18b2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AC58u; }
        if (ctx->pc != 0x18AC58u) { return; }
    }
    ctx->pc = 0x18AC58u;
label_18ac58:
    // 0x18ac58: 0xe6a00000  swc1        $f0, 0x0($s5)
    ctx->pc = 0x18ac58u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 0), bits); }
    // 0x18ac5c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x18ac5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18ac60: 0x8e220018  lw          $v0, 0x18($s1)
    ctx->pc = 0x18ac60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x18ac64: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x18ac64u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x18ac68: 0xc062cb0  jal         func_18B2C0
    ctx->pc = 0x18AC68u;
    SET_GPR_U32(ctx, 31, 0x18AC70u);
    ctx->pc = 0x18AC6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18AC68u;
            // 0x18ac6c: 0x304400ff  andi        $a0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B2C0u;
    if (runtime->hasFunction(0x18B2C0u)) {
        auto targetFn = runtime->lookupFunction(0x18B2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AC70u; }
        if (ctx->pc != 0x18AC70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B2C0_0x18b2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AC70u; }
        if (ctx->pc != 0x18AC70u) { return; }
    }
    ctx->pc = 0x18AC70u;
label_18ac70:
    // 0x18ac70: 0xe6a00004  swc1        $f0, 0x4($s5)
    ctx->pc = 0x18ac70u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 4), bits); }
    // 0x18ac74: 0x92240018  lbu         $a0, 0x18($s1)
    ctx->pc = 0x18ac74u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x18ac78: 0xc062cb0  jal         func_18B2C0
    ctx->pc = 0x18AC78u;
    SET_GPR_U32(ctx, 31, 0x18AC80u);
    ctx->pc = 0x18AC7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18AC78u;
            // 0x18ac7c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B2C0u;
    if (runtime->hasFunction(0x18B2C0u)) {
        auto targetFn = runtime->lookupFunction(0x18B2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AC80u; }
        if (ctx->pc != 0x18AC80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B2C0_0x18b2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AC80u; }
        if (ctx->pc != 0x18AC80u) { return; }
    }
    ctx->pc = 0x18AC80u;
label_18ac80:
    // 0x18ac80: 0xe6a00008  swc1        $f0, 0x8($s5)
    ctx->pc = 0x18ac80u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 8), bits); }
label_18ac84:
    // 0x18ac84: 0x8e220018  lw          $v0, 0x18($s1)
    ctx->pc = 0x18ac84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x18ac88: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x18ac88u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ac8c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x18ac8cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x18ac90: 0xc062cb0  jal         func_18B2C0
    ctx->pc = 0x18AC90u;
    SET_GPR_U32(ctx, 31, 0x18AC98u);
    ctx->pc = 0x18AC94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18AC90u;
            // 0x18ac94: 0x304400ff  andi        $a0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B2C0u;
    if (runtime->hasFunction(0x18B2C0u)) {
        auto targetFn = runtime->lookupFunction(0x18B2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AC98u; }
        if (ctx->pc != 0x18AC98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B2C0_0x18b2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AC98u; }
        if (ctx->pc != 0x18AC98u) { return; }
    }
    ctx->pc = 0x18AC98u;
label_18ac98:
    // 0x18ac98: 0xe6a0000c  swc1        $f0, 0xC($s5)
    ctx->pc = 0x18ac98u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 12), bits); }
    // 0x18ac9c: 0x26b50010  addiu       $s5, $s5, 0x10
    ctx->pc = 0x18ac9cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 16));
label_18aca0:
    // 0x18aca0: 0x8fa200e0  lw          $v0, 0xE0($sp)
    ctx->pc = 0x18aca0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 224)));
    // 0x18aca4: 0x104000fe  beqz        $v0, . + 4 + (0xFE << 2)
    ctx->pc = 0x18ACA4u;
    {
        const bool branch_taken_0x18aca4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18aca4) {
            ctx->pc = 0x18B0A0u;
            goto label_18b0a0;
        }
    }
    ctx->pc = 0x18ACACu;
    // 0x18acac: 0xc620001c  lwc1        $f0, 0x1C($s1)
    ctx->pc = 0x18acacu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18acb0: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x18acb0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x18acb4: 0x2a0182d  daddu       $v1, $s5, $zero
    ctx->pc = 0x18acb4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18acb8: 0xe6a00000  swc1        $f0, 0x0($s5)
    ctx->pc = 0x18acb8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 0), bits); }
    // 0x18acbc: 0xc6200020  lwc1        $f0, 0x20($s1)
    ctx->pc = 0x18acbcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18acc0: 0xe6a00004  swc1        $f0, 0x4($s5)
    ctx->pc = 0x18acc0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 4), bits); }
    // 0x18acc4: 0xaea20008  sw          $v0, 0x8($s5)
    ctx->pc = 0x18acc4u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 8), GPR_U32(ctx, 2));
    // 0x18acc8: 0xaea0000c  sw          $zero, 0xC($s5)
    ctx->pc = 0x18acc8u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 0));
    // 0x18accc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x18acccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x18acd0: 0x30420020  andi        $v0, $v0, 0x20
    ctx->pc = 0x18acd0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32);
    // 0x18acd4: 0x104000f2  beqz        $v0, . + 4 + (0xF2 << 2)
    ctx->pc = 0x18ACD4u;
    {
        const bool branch_taken_0x18acd4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x18ACD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18ACD4u;
            // 0x18acd8: 0x26b50010  addiu       $s5, $s5, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18acd4) {
            ctx->pc = 0x18B0A0u;
            goto label_18b0a0;
        }
    }
    ctx->pc = 0x18ACDCu;
    // 0x18acdc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18acdcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18ace0: 0xc4204188  lwc1        $f0, 0x4188($at)
    ctx->pc = 0x18ace0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16776)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18ace4: 0xc4610000  lwc1        $f1, 0x0($v1)
    ctx->pc = 0x18ace4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x18ace8: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18ace8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18acec: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x18acecu;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x18acf0: 0xe4600000  swc1        $f0, 0x0($v1)
    ctx->pc = 0x18acf0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 0), bits); }
    // 0x18acf4: 0xc4610004  lwc1        $f1, 0x4($v1)
    ctx->pc = 0x18acf4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x18acf8: 0xc4204180  lwc1        $f0, 0x4180($at)
    ctx->pc = 0x18acf8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16768)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18acfc: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x18acfcu;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x18ad00: 0x100000e7  b           . + 4 + (0xE7 << 2)
    ctx->pc = 0x18AD00u;
    {
        const bool branch_taken_0x18ad00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18AD04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18AD00u;
            // 0x18ad04: 0xe4600004  swc1        $f0, 0x4($v1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 4), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ad00) {
            ctx->pc = 0x18B0A0u;
            goto label_18b0a0;
        }
    }
    ctx->pc = 0x18AD08u;
label_18ad08:
    // 0x18ad08: 0x8fa2026c  lw          $v0, 0x26C($sp)
    ctx->pc = 0x18ad08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 620)));
    // 0x18ad0c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x18ad0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18ad10: 0x30421000  andi        $v0, $v0, 0x1000
    ctx->pc = 0x18ad10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4096);
    // 0x18ad14: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x18AD14u;
    {
        const bool branch_taken_0x18ad14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18ad14) {
            ctx->pc = 0x18AD48u;
            goto label_18ad48;
        }
    }
    ctx->pc = 0x18AD1Cu;
    // 0x18ad1c: 0x8fa2026c  lw          $v0, 0x26C($sp)
    ctx->pc = 0x18ad1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 620)));
    // 0x18ad20: 0x96440000  lhu         $a0, 0x0($s2)
    ctx->pc = 0x18ad20u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18ad24: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x18ad24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x18ad28: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x18ad28u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x18ad2c: 0x26520002  addiu       $s2, $s2, 0x2
    ctx->pc = 0x18ad2cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
    // 0x18ad30: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x18ad30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x18ad34: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x18ad34u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x18ad38: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x18ad38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x18ad3c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x18ad3cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18ad40: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x18AD40u;
    {
        const bool branch_taken_0x18ad40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18AD44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18AD40u;
            // 0x18ad44: 0x438021  addu        $s0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ad40) {
            ctx->pc = 0x18AD4Cu;
            goto label_18ad4c;
        }
    }
    ctx->pc = 0x18AD48u;
label_18ad48:
    // 0x18ad48: 0x2610002c  addiu       $s0, $s0, 0x2C
    ctx->pc = 0x18ad48u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 44));
label_18ad4c:
    // 0x18ad4c: 0x8fa20110  lw          $v0, 0x110($sp)
    ctx->pc = 0x18ad4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 272)));
    // 0x18ad50: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x18AD50u;
    {
        const bool branch_taken_0x18ad50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18ad50) {
            ctx->pc = 0x18AD90u;
            goto label_18ad90;
        }
    }
    ctx->pc = 0x18AD58u;
    // 0x18ad58: 0xc6000000  lwc1        $f0, 0x0($s0)
    ctx->pc = 0x18ad58u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18ad5c: 0xe6a00000  swc1        $f0, 0x0($s5)
    ctx->pc = 0x18ad5cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 0), bits); }
    // 0x18ad60: 0xc6000004  lwc1        $f0, 0x4($s0)
    ctx->pc = 0x18ad60u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18ad64: 0xe6a00004  swc1        $f0, 0x4($s5)
    ctx->pc = 0x18ad64u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 4), bits); }
    // 0x18ad68: 0xc6000008  lwc1        $f0, 0x8($s0)
    ctx->pc = 0x18ad68u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18ad6c: 0xe6a00008  swc1        $f0, 0x8($s5)
    ctx->pc = 0x18ad6cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 8), bits); }
    // 0x18ad70: 0x8fa20250  lw          $v0, 0x250($sp)
    ctx->pc = 0x18ad70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 592)));
    // 0x18ad74: 0x28410002  slti        $at, $v0, 0x2
    ctx->pc = 0x18ad74u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x18ad78: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x18AD78u;
    {
        const bool branch_taken_0x18ad78 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x18AD7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18AD78u;
            // 0x18ad7c: 0x34028000  ori         $v0, $zero, 0x8000 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ad78) {
            ctx->pc = 0x18AD88u;
            goto label_18ad88;
        }
    }
    ctx->pc = 0x18AD80u;
    // 0x18ad80: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x18AD80u;
    {
        const bool branch_taken_0x18ad80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18AD84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18AD80u;
            // 0x18ad84: 0xaea2000c  sw          $v0, 0xC($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ad80) {
            ctx->pc = 0x18AD8Cu;
            goto label_18ad8c;
        }
    }
    ctx->pc = 0x18AD88u;
label_18ad88:
    // 0x18ad88: 0xaea0000c  sw          $zero, 0xC($s5)
    ctx->pc = 0x18ad88u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 0));
label_18ad8c:
    // 0x18ad8c: 0x26b50010  addiu       $s5, $s5, 0x10
    ctx->pc = 0x18ad8cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 16));
label_18ad90:
    // 0x18ad90: 0x8fa20100  lw          $v0, 0x100($sp)
    ctx->pc = 0x18ad90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 256)));
    // 0x18ad94: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x18AD94u;
    {
        const bool branch_taken_0x18ad94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18ad94) {
            ctx->pc = 0x18ADD4u;
            goto label_18add4;
        }
    }
    ctx->pc = 0x18AD9Cu;
    // 0x18ad9c: 0xc600000c  lwc1        $f0, 0xC($s0)
    ctx->pc = 0x18ad9cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18ada0: 0xe6a00000  swc1        $f0, 0x0($s5)
    ctx->pc = 0x18ada0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 0), bits); }
    // 0x18ada4: 0xc6000010  lwc1        $f0, 0x10($s0)
    ctx->pc = 0x18ada4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18ada8: 0xe6a00004  swc1        $f0, 0x4($s5)
    ctx->pc = 0x18ada8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 4), bits); }
    // 0x18adac: 0xc6000014  lwc1        $f0, 0x14($s0)
    ctx->pc = 0x18adacu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18adb0: 0xe6a00008  swc1        $f0, 0x8($s5)
    ctx->pc = 0x18adb0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 8), bits); }
    // 0x18adb4: 0x8fa20160  lw          $v0, 0x160($sp)
    ctx->pc = 0x18adb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 352)));
    // 0x18adb8: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18ADB8u;
    {
        const bool branch_taken_0x18adb8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18ADBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18ADB8u;
            // 0x18adbc: 0x3c02bf80  lui         $v0, 0xBF80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18adb8) {
            ctx->pc = 0x18ADCCu;
            goto label_18adcc;
        }
    }
    ctx->pc = 0x18ADC0u;
    // 0x18adc0: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x18adc0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x18adc4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x18ADC4u;
    {
        const bool branch_taken_0x18adc4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18ADC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18ADC4u;
            // 0x18adc8: 0xaea2000c  sw          $v0, 0xC($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18adc4) {
            ctx->pc = 0x18ADD0u;
            goto label_18add0;
        }
    }
    ctx->pc = 0x18ADCCu;
label_18adcc:
    // 0x18adcc: 0xaea2000c  sw          $v0, 0xC($s5)
    ctx->pc = 0x18adccu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 2));
label_18add0:
    // 0x18add0: 0x26b50010  addiu       $s5, $s5, 0x10
    ctx->pc = 0x18add0u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 16));
label_18add4:
    // 0x18add4: 0x8fa200f0  lw          $v0, 0xF0($sp)
    ctx->pc = 0x18add4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 240)));
    // 0x18add8: 0x1040002d  beqz        $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x18ADD8u;
    {
        const bool branch_taken_0x18add8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18add8) {
            ctx->pc = 0x18AE90u;
            goto label_18ae90;
        }
    }
    ctx->pc = 0x18ADE0u;
    // 0x18ade0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x18ade0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x18ade4: 0x30420f00  andi        $v0, $v0, 0xF00
    ctx->pc = 0x18ade4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3840);
    // 0x18ade8: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x18ADE8u;
    {
        const bool branch_taken_0x18ade8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18ade8) {
            ctx->pc = 0x18AE34u;
            goto label_18ae34;
        }
    }
    ctx->pc = 0x18ADF0u;
    // 0x18adf0: 0x8e020018  lw          $v0, 0x18($s0)
    ctx->pc = 0x18adf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x18adf4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x18adf4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18adf8: 0x21402  srl         $v0, $v0, 16
    ctx->pc = 0x18adf8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x18adfc: 0xc062cb0  jal         func_18B2C0
    ctx->pc = 0x18ADFCu;
    SET_GPR_U32(ctx, 31, 0x18AE04u);
    ctx->pc = 0x18AE00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18ADFCu;
            // 0x18ae00: 0x304400ff  andi        $a0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B2C0u;
    if (runtime->hasFunction(0x18B2C0u)) {
        auto targetFn = runtime->lookupFunction(0x18B2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AE04u; }
        if (ctx->pc != 0x18AE04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B2C0_0x18b2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AE04u; }
        if (ctx->pc != 0x18AE04u) { return; }
    }
    ctx->pc = 0x18AE04u;
label_18ae04:
    // 0x18ae04: 0xe6a00000  swc1        $f0, 0x0($s5)
    ctx->pc = 0x18ae04u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 0), bits); }
    // 0x18ae08: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x18ae08u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ae0c: 0x8e020018  lw          $v0, 0x18($s0)
    ctx->pc = 0x18ae0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x18ae10: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x18ae10u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x18ae14: 0xc062cb0  jal         func_18B2C0
    ctx->pc = 0x18AE14u;
    SET_GPR_U32(ctx, 31, 0x18AE1Cu);
    ctx->pc = 0x18AE18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18AE14u;
            // 0x18ae18: 0x304400ff  andi        $a0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B2C0u;
    if (runtime->hasFunction(0x18B2C0u)) {
        auto targetFn = runtime->lookupFunction(0x18B2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AE1Cu; }
        if (ctx->pc != 0x18AE1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B2C0_0x18b2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AE1Cu; }
        if (ctx->pc != 0x18AE1Cu) { return; }
    }
    ctx->pc = 0x18AE1Cu;
label_18ae1c:
    // 0x18ae1c: 0xe6a00004  swc1        $f0, 0x4($s5)
    ctx->pc = 0x18ae1cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 4), bits); }
    // 0x18ae20: 0x92040018  lbu         $a0, 0x18($s0)
    ctx->pc = 0x18ae20u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x18ae24: 0xc062cb0  jal         func_18B2C0
    ctx->pc = 0x18AE24u;
    SET_GPR_U32(ctx, 31, 0x18AE2Cu);
    ctx->pc = 0x18AE28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18AE24u;
            // 0x18ae28: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B2C0u;
    if (runtime->hasFunction(0x18B2C0u)) {
        auto targetFn = runtime->lookupFunction(0x18B2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AE2Cu; }
        if (ctx->pc != 0x18AE2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B2C0_0x18b2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AE2Cu; }
        if (ctx->pc != 0x18AE2Cu) { return; }
    }
    ctx->pc = 0x18AE2Cu;
label_18ae2c:
    // 0x18ae2c: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x18AE2Cu;
    {
        const bool branch_taken_0x18ae2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18AE30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18AE2Cu;
            // 0x18ae30: 0xe6a00008  swc1        $f0, 0x8($s5) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 8), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ae2c) {
            ctx->pc = 0x18AE74u;
            goto label_18ae74;
        }
    }
    ctx->pc = 0x18AE34u;
label_18ae34:
    // 0x18ae34: 0x8e020018  lw          $v0, 0x18($s0)
    ctx->pc = 0x18ae34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x18ae38: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x18ae38u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18ae3c: 0x21402  srl         $v0, $v0, 16
    ctx->pc = 0x18ae3cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x18ae40: 0xc062cb0  jal         func_18B2C0
    ctx->pc = 0x18AE40u;
    SET_GPR_U32(ctx, 31, 0x18AE48u);
    ctx->pc = 0x18AE44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18AE40u;
            // 0x18ae44: 0x304400ff  andi        $a0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B2C0u;
    if (runtime->hasFunction(0x18B2C0u)) {
        auto targetFn = runtime->lookupFunction(0x18B2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AE48u; }
        if (ctx->pc != 0x18AE48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B2C0_0x18b2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AE48u; }
        if (ctx->pc != 0x18AE48u) { return; }
    }
    ctx->pc = 0x18AE48u;
label_18ae48:
    // 0x18ae48: 0xe6a00000  swc1        $f0, 0x0($s5)
    ctx->pc = 0x18ae48u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 0), bits); }
    // 0x18ae4c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x18ae4cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18ae50: 0x8e020018  lw          $v0, 0x18($s0)
    ctx->pc = 0x18ae50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x18ae54: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x18ae54u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x18ae58: 0xc062cb0  jal         func_18B2C0
    ctx->pc = 0x18AE58u;
    SET_GPR_U32(ctx, 31, 0x18AE60u);
    ctx->pc = 0x18AE5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18AE58u;
            // 0x18ae5c: 0x304400ff  andi        $a0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B2C0u;
    if (runtime->hasFunction(0x18B2C0u)) {
        auto targetFn = runtime->lookupFunction(0x18B2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AE60u; }
        if (ctx->pc != 0x18AE60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B2C0_0x18b2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AE60u; }
        if (ctx->pc != 0x18AE60u) { return; }
    }
    ctx->pc = 0x18AE60u;
label_18ae60:
    // 0x18ae60: 0xe6a00004  swc1        $f0, 0x4($s5)
    ctx->pc = 0x18ae60u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 4), bits); }
    // 0x18ae64: 0x92040018  lbu         $a0, 0x18($s0)
    ctx->pc = 0x18ae64u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x18ae68: 0xc062cb0  jal         func_18B2C0
    ctx->pc = 0x18AE68u;
    SET_GPR_U32(ctx, 31, 0x18AE70u);
    ctx->pc = 0x18AE6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18AE68u;
            // 0x18ae6c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B2C0u;
    if (runtime->hasFunction(0x18B2C0u)) {
        auto targetFn = runtime->lookupFunction(0x18B2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AE70u; }
        if (ctx->pc != 0x18AE70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B2C0_0x18b2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AE70u; }
        if (ctx->pc != 0x18AE70u) { return; }
    }
    ctx->pc = 0x18AE70u;
label_18ae70:
    // 0x18ae70: 0xe6a00008  swc1        $f0, 0x8($s5)
    ctx->pc = 0x18ae70u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 8), bits); }
label_18ae74:
    // 0x18ae74: 0x8e020018  lw          $v0, 0x18($s0)
    ctx->pc = 0x18ae74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x18ae78: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x18ae78u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ae7c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x18ae7cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x18ae80: 0xc062cb0  jal         func_18B2C0
    ctx->pc = 0x18AE80u;
    SET_GPR_U32(ctx, 31, 0x18AE88u);
    ctx->pc = 0x18AE84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18AE80u;
            // 0x18ae84: 0x304400ff  andi        $a0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B2C0u;
    if (runtime->hasFunction(0x18B2C0u)) {
        auto targetFn = runtime->lookupFunction(0x18B2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AE88u; }
        if (ctx->pc != 0x18AE88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B2C0_0x18b2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18AE88u; }
        if (ctx->pc != 0x18AE88u) { return; }
    }
    ctx->pc = 0x18AE88u;
label_18ae88:
    // 0x18ae88: 0xe6a0000c  swc1        $f0, 0xC($s5)
    ctx->pc = 0x18ae88u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 12), bits); }
    // 0x18ae8c: 0x26b50010  addiu       $s5, $s5, 0x10
    ctx->pc = 0x18ae8cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 16));
label_18ae90:
    // 0x18ae90: 0x8fa200e0  lw          $v0, 0xE0($sp)
    ctx->pc = 0x18ae90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 224)));
    // 0x18ae94: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x18AE94u;
    {
        const bool branch_taken_0x18ae94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18ae94) {
            ctx->pc = 0x18AEF4u;
            goto label_18aef4;
        }
    }
    ctx->pc = 0x18AE9Cu;
    // 0x18ae9c: 0xc600001c  lwc1        $f0, 0x1C($s0)
    ctx->pc = 0x18ae9cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18aea0: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x18aea0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x18aea4: 0x2a0182d  daddu       $v1, $s5, $zero
    ctx->pc = 0x18aea4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18aea8: 0xe6a00000  swc1        $f0, 0x0($s5)
    ctx->pc = 0x18aea8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 0), bits); }
    // 0x18aeac: 0xc6000020  lwc1        $f0, 0x20($s0)
    ctx->pc = 0x18aeacu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18aeb0: 0xe6a00004  swc1        $f0, 0x4($s5)
    ctx->pc = 0x18aeb0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 4), bits); }
    // 0x18aeb4: 0xaea20008  sw          $v0, 0x8($s5)
    ctx->pc = 0x18aeb4u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 8), GPR_U32(ctx, 2));
    // 0x18aeb8: 0xaea0000c  sw          $zero, 0xC($s5)
    ctx->pc = 0x18aeb8u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 0));
    // 0x18aebc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x18aebcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x18aec0: 0x30420020  andi        $v0, $v0, 0x20
    ctx->pc = 0x18aec0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32);
    // 0x18aec4: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x18AEC4u;
    {
        const bool branch_taken_0x18aec4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x18AEC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18AEC4u;
            // 0x18aec8: 0x26b50010  addiu       $s5, $s5, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18aec4) {
            ctx->pc = 0x18AEF4u;
            goto label_18aef4;
        }
    }
    ctx->pc = 0x18AECCu;
    // 0x18aecc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18aeccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18aed0: 0xc4204188  lwc1        $f0, 0x4188($at)
    ctx->pc = 0x18aed0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16776)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18aed4: 0xc4610000  lwc1        $f1, 0x0($v1)
    ctx->pc = 0x18aed4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x18aed8: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18aed8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18aedc: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x18aedcu;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x18aee0: 0xe4600000  swc1        $f0, 0x0($v1)
    ctx->pc = 0x18aee0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 0), bits); }
    // 0x18aee4: 0xc4610004  lwc1        $f1, 0x4($v1)
    ctx->pc = 0x18aee4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x18aee8: 0xc4204180  lwc1        $f0, 0x4180($at)
    ctx->pc = 0x18aee8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16768)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18aeec: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x18aeecu;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x18aef0: 0xe4600004  swc1        $f0, 0x4($v1)
    ctx->pc = 0x18aef0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 4), bits); }
label_18aef4:
    // 0x18aef4: 0x8fa200d0  lw          $v0, 0xD0($sp)
    ctx->pc = 0x18aef4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x18aef8: 0x10400069  beqz        $v0, . + 4 + (0x69 << 2)
    ctx->pc = 0x18AEF8u;
    {
        const bool branch_taken_0x18aef8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18aef8) {
            ctx->pc = 0x18B0A0u;
            goto label_18b0a0;
        }
    }
    ctx->pc = 0x18AF00u;
    // 0x18af00: 0x8fa200c0  lw          $v0, 0xC0($sp)
    ctx->pc = 0x18af00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x18af04: 0x10400066  beqz        $v0, . + 4 + (0x66 << 2)
    ctx->pc = 0x18AF04u;
    {
        const bool branch_taken_0x18af04 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18af04) {
            ctx->pc = 0x18B0A0u;
            goto label_18b0a0;
        }
    }
    ctx->pc = 0x18AF0Cu;
    // 0x18af0c: 0x8e020024  lw          $v0, 0x24($s0)
    ctx->pc = 0x18af0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x18af10: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x18af10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18af14: 0x26a50010  addiu       $a1, $s5, 0x10
    ctx->pc = 0x18af14u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), 16));
    // 0x18af18: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x18af18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18af1c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x18af1cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x18af20: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x18af20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x18af24: 0xafa20300  sw          $v0, 0x300($sp)
    ctx->pc = 0x18af24u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 768), GPR_U32(ctx, 2));
    // 0x18af28: 0x8e020024  lw          $v0, 0x24($s0)
    ctx->pc = 0x18af28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x18af2c: 0x21402  srl         $v0, $v0, 16
    ctx->pc = 0x18af2cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x18af30: 0x304600ff  andi        $a2, $v0, 0xFF
    ctx->pc = 0x18af30u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x18af34: 0x27a20304  addiu       $v0, $sp, 0x304
    ctx->pc = 0x18af34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 772));
    // 0x18af38: 0xac460000  sw          $a2, 0x0($v0)
    ctx->pc = 0x18af38u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 6));
    // 0x18af3c: 0x8e020024  lw          $v0, 0x24($s0)
    ctx->pc = 0x18af3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x18af40: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x18af40u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x18af44: 0x304600ff  andi        $a2, $v0, 0xFF
    ctx->pc = 0x18af44u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x18af48: 0x27a20308  addiu       $v0, $sp, 0x308
    ctx->pc = 0x18af48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 776));
    // 0x18af4c: 0xac460000  sw          $a2, 0x0($v0)
    ctx->pc = 0x18af4cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 6));
    // 0x18af50: 0x92060024  lbu         $a2, 0x24($s0)
    ctx->pc = 0x18af50u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x18af54: 0x27a2030c  addiu       $v0, $sp, 0x30C
    ctx->pc = 0x18af54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 780));
    // 0x18af58: 0xac460000  sw          $a2, 0x0($v0)
    ctx->pc = 0x18af58u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 6));
    // 0x18af5c: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x18af5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x18af60: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x18af60u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x18af64: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x18af64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x18af68: 0xafa202f0  sw          $v0, 0x2F0($sp)
    ctx->pc = 0x18af68u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 752), GPR_U32(ctx, 2));
    // 0x18af6c: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x18af6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x18af70: 0x21402  srl         $v0, $v0, 16
    ctx->pc = 0x18af70u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x18af74: 0x304600ff  andi        $a2, $v0, 0xFF
    ctx->pc = 0x18af74u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x18af78: 0x27a202f4  addiu       $v0, $sp, 0x2F4
    ctx->pc = 0x18af78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 756));
    // 0x18af7c: 0xac460000  sw          $a2, 0x0($v0)
    ctx->pc = 0x18af7cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 6));
    // 0x18af80: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x18af80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x18af84: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x18af84u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x18af88: 0x304600ff  andi        $a2, $v0, 0xFF
    ctx->pc = 0x18af88u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x18af8c: 0x27a202f8  addiu       $v0, $sp, 0x2F8
    ctx->pc = 0x18af8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 760));
    // 0x18af90: 0xac460000  sw          $a2, 0x0($v0)
    ctx->pc = 0x18af90u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 6));
    // 0x18af94: 0x92060028  lbu         $a2, 0x28($s0)
    ctx->pc = 0x18af94u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x18af98: 0x27a202fc  addiu       $v0, $sp, 0x2FC
    ctx->pc = 0x18af98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 764));
    // 0x18af9c: 0xac460000  sw          $a2, 0x0($v0)
    ctx->pc = 0x18af9cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 6));
    // 0x18afa0: 0x7c800000  sq          $zero, 0x0($a0)
    ctx->pc = 0x18afa0u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 0));
    // 0x18afa4: 0x7ca00000  sq          $zero, 0x0($a1)
    ctx->pc = 0x18afa4u;
    WRITE128(ADD32(GPR_U32(ctx, 5), 0), GPR_VEC(ctx, 0));
    // 0x18afa8: 0x8fa20210  lw          $v0, 0x210($sp)
    ctx->pc = 0x18afa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 528)));
    // 0x18afac: 0x1043001f  beq         $v0, $v1, . + 4 + (0x1F << 2)
    ctx->pc = 0x18AFACu;
    {
        const bool branch_taken_0x18afac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x18AFB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18AFACu;
            // 0x18afb0: 0x26b50020  addiu       $s5, $s5, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18afac) {
            ctx->pc = 0x18B02Cu;
            goto label_18b02c;
        }
    }
    ctx->pc = 0x18AFB4u;
    // 0x18afb4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18AFB4u;
    {
        const bool branch_taken_0x18afb4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18afb4) {
            ctx->pc = 0x18AFC4u;
            goto label_18afc4;
        }
    }
    ctx->pc = 0x18AFBCu;
    // 0x18afbc: 0x10000038  b           . + 4 + (0x38 << 2)
    ctx->pc = 0x18AFBCu;
    {
        const bool branch_taken_0x18afbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18afbc) {
            ctx->pc = 0x18B0A0u;
            goto label_18b0a0;
        }
    }
    ctx->pc = 0x18AFC4u;
label_18afc4:
    // 0x18afc4: 0x8fa20180  lw          $v0, 0x180($sp)
    ctx->pc = 0x18afc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 384)));
    // 0x18afc8: 0x3c0642c8  lui         $a2, 0x42C8
    ctx->pc = 0x18afc8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)17096 << 16));
    // 0x18afcc: 0x8fa70300  lw          $a3, 0x300($sp)
    ctx->pc = 0x18afccu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 768)));
    // 0x18afd0: 0x8c420028  lw          $v0, 0x28($v0)
    ctx->pc = 0x18afd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x18afd4: 0x73880  sll         $a3, $a3, 2
    ctx->pc = 0x18afd4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x18afd8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x18afd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18afdc: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x18afdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x18afe0: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x18afe0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x18afe4: 0x8fa70300  lw          $a3, 0x300($sp)
    ctx->pc = 0x18afe4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 768)));
    // 0x18afe8: 0x8fc20054  lw          $v0, 0x54($fp)
    ctx->pc = 0x18afe8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x18afec: 0xe31804  sllv        $v1, $v1, $a3
    ctx->pc = 0x18afecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 7) & 0x1F));
    // 0x18aff0: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x18aff0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x18aff4: 0xafc20054  sw          $v0, 0x54($fp)
    ctx->pc = 0x18aff4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 84), GPR_U32(ctx, 2));
    // 0x18aff8: 0x8fa20180  lw          $v0, 0x180($sp)
    ctx->pc = 0x18aff8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 384)));
    // 0x18affc: 0x8fa30300  lw          $v1, 0x300($sp)
    ctx->pc = 0x18affcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 768)));
    // 0x18b000: 0x8c420028  lw          $v0, 0x28($v0)
    ctx->pc = 0x18b000u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x18b004: 0x8c480004  lw          $t0, 0x4($v0)
    ctx->pc = 0x18b004u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x18b008: 0x8c470000  lw          $a3, 0x0($v0)
    ctx->pc = 0x18b008u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18b00c: 0x84080  sll         $t0, $t0, 2
    ctx->pc = 0x18b00cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x18b010: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x18b010u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x18b014: 0xe83821  addu        $a3, $a3, $t0
    ctx->pc = 0x18b014u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x18b018: 0x621018  mult        $v0, $v1, $v0
    ctx->pc = 0x18b018u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x18b01c: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x18b01cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x18b020: 0xac820004  sw          $v0, 0x4($a0)
    ctx->pc = 0x18b020u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 2));
    // 0x18b024: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x18B024u;
    {
        const bool branch_taken_0x18b024 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18B028u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B024u;
            // 0x18b028: 0xaca60000  sw          $a2, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b024) {
            ctx->pc = 0x18B0A0u;
            goto label_18b0a0;
        }
    }
    ctx->pc = 0x18B02Cu;
label_18b02c:
    // 0x18b02c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x18b02cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b030: 0x3c02437f  lui         $v0, 0x437F
    ctx->pc = 0x18b030u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17279 << 16));
    // 0x18b034: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x18b034u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
label_18b038:
    // 0x18b038: 0x8fa20180  lw          $v0, 0x180($sp)
    ctx->pc = 0x18b038u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 384)));
    // 0x18b03c: 0x63880  sll         $a3, $a2, 2
    ctx->pc = 0x18b03cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x18b040: 0x874821  addu        $t1, $a0, $a3
    ctx->pc = 0x18b040u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x18b044: 0xa74021  addu        $t0, $a1, $a3
    ctx->pc = 0x18b044u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x18b048: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x18b048u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x18b04c: 0x8c4a0028  lw          $t2, 0x28($v0)
    ctx->pc = 0x18b04cu;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x18b050: 0xfd1021  addu        $v0, $a3, $sp
    ctx->pc = 0x18b050u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 29)));
    // 0x18b054: 0x8d4a0000  lw          $t2, 0x0($t2)
    ctx->pc = 0x18b054u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x18b058: 0x244c0300  addiu       $t4, $v0, 0x300
    ctx->pc = 0x18b058u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 2), 768));
    // 0x18b05c: 0x28c70004  slti        $a3, $a2, 0x4
    ctx->pc = 0x18b05cu;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x18b060: 0x8d8b0000  lw          $t3, 0x0($t4)
    ctx->pc = 0x18b060u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x18b064: 0xb5880  sll         $t3, $t3, 2
    ctx->pc = 0x18b064u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 2));
    // 0x18b068: 0x14b5021  addu        $t2, $t2, $t3
    ctx->pc = 0x18b068u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 11)));
    // 0x18b06c: 0xad2a0000  sw          $t2, 0x0($t1)
    ctx->pc = 0x18b06cu;
    WRITE32(ADD32(GPR_U32(ctx, 9), 0), GPR_U32(ctx, 10));
    // 0x18b070: 0x8d8a0000  lw          $t2, 0x0($t4)
    ctx->pc = 0x18b070u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x18b074: 0x8fc90054  lw          $t1, 0x54($fp)
    ctx->pc = 0x18b074u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x18b078: 0x1435004  sllv        $t2, $v1, $t2
    ctx->pc = 0x18b078u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 10) & 0x1F));
    // 0x18b07c: 0x12a4825  or          $t1, $t1, $t2
    ctx->pc = 0x18b07cu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 10));
    // 0x18b080: 0xafc90054  sw          $t1, 0x54($fp)
    ctx->pc = 0x18b080u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 84), GPR_U32(ctx, 9));
    // 0x18b084: 0xc44002f0  lwc1        $f0, 0x2F0($v0)
    ctx->pc = 0x18b084u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 752)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b088: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18b088u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18b08c: 0x46010003  div.s       $f0, $f0, $f1
    ctx->pc = 0x18b08cu;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x18b090: 0x0  nop
    ctx->pc = 0x18b090u;
    // NOP
    // 0x18b094: 0x0  nop
    ctx->pc = 0x18b094u;
    // NOP
    // 0x18b098: 0x14e0ffe7  bnez        $a3, . + 4 + (-0x19 << 2)
    ctx->pc = 0x18B098u;
    {
        const bool branch_taken_0x18b098 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x18B09Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B098u;
            // 0x18b09c: 0xe5000000  swc1        $f0, 0x0($t0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 8), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b098) {
            ctx->pc = 0x18B038u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18b038;
        }
    }
    ctx->pc = 0x18B0A0u;
label_18b0a0:
    // 0x18b0a0: 0x8fa20160  lw          $v0, 0x160($sp)
    ctx->pc = 0x18b0a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 352)));
label_18b0a4:
    // 0x18b0a4: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x18b0a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x18b0a8: 0xafa20160  sw          $v0, 0x160($sp)
    ctx->pc = 0x18b0a8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 352), GPR_U32(ctx, 2));
    // 0x18b0ac: 0x8fa20250  lw          $v0, 0x250($sp)
    ctx->pc = 0x18b0acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 592)));
    // 0x18b0b0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x18b0b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x18b0b4: 0xafa20250  sw          $v0, 0x250($sp)
    ctx->pc = 0x18b0b4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 592), GPR_U32(ctx, 2));
label_18b0b8:
    // 0x18b0b8: 0x8fa30250  lw          $v1, 0x250($sp)
    ctx->pc = 0x18b0b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 592)));
    // 0x18b0bc: 0x8fa200b0  lw          $v0, 0xB0($sp)
    ctx->pc = 0x18b0bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x18b0c0: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x18b0c0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x18b0c4: 0x1440fdbe  bnez        $v0, . + 4 + (-0x242 << 2)
    ctx->pc = 0x18B0C4u;
    {
        const bool branch_taken_0x18b0c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18b0c4) {
            ctx->pc = 0x18A7C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18a7c0;
        }
    }
    ctx->pc = 0x18B0CCu;
    // 0x18b0cc: 0x8fa200a0  lw          $v0, 0xA0($sp)
    ctx->pc = 0x18b0ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x18b0d0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x18b0d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x18b0d4: 0xafa200a0  sw          $v0, 0xA0($sp)
    ctx->pc = 0x18b0d4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 160), GPR_U32(ctx, 2));
label_18b0d8:
    // 0x18b0d8: 0x8fa300a0  lw          $v1, 0xA0($sp)
    ctx->pc = 0x18b0d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x18b0dc: 0x8fa201d0  lw          $v0, 0x1D0($sp)
    ctx->pc = 0x18b0dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 464)));
    // 0x18b0e0: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x18b0e0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x18b0e4: 0x1440fce2  bnez        $v0, . + 4 + (-0x31E << 2)
    ctx->pc = 0x18B0E4u;
    {
        const bool branch_taken_0x18b0e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18b0e4) {
            ctx->pc = 0x18A470u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18a470;
        }
    }
    ctx->pc = 0x18B0ECu;
    // 0x18b0ec: 0x1260002b  beqz        $s3, . + 4 + (0x2B << 2)
    ctx->pc = 0x18B0ECu;
    {
        const bool branch_taken_0x18b0ec = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        if (branch_taken_0x18b0ec) {
            ctx->pc = 0x18B19Cu;
            goto label_18b19c;
        }
    }
    ctx->pc = 0x18B0F4u;
    // 0x18b0f4: 0x8fa201f0  lw          $v0, 0x1F0($sp)
    ctx->pc = 0x18b0f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 496)));
    // 0x18b0f8: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x18b0f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b0fc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x18b0fcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b100: 0xc063204  jal         func_18C810
    ctx->pc = 0x18B100u;
    SET_GPR_U32(ctx, 31, 0x18B108u);
    ctx->pc = 0x18B104u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B100u;
            // 0x18b104: 0x22902  srl         $a1, $v0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C810u;
    if (runtime->hasFunction(0x18C810u)) {
        auto targetFn = runtime->lookupFunction(0x18C810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B108u; }
        if (ctx->pc != 0x18B108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C810_0x18c810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B108u; }
        if (ctx->pc != 0x18B108u) { return; }
    }
    ctx->pc = 0x18B108u;
label_18b108:
    // 0x18b108: 0x8fa30210  lw          $v1, 0x210($sp)
    ctx->pc = 0x18b108u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 528)));
    // 0x18b10c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x18b10cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18b110: 0x10640007  beq         $v1, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x18B110u;
    {
        const bool branch_taken_0x18b110 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x18b110) {
            ctx->pc = 0x18B130u;
            goto label_18b130;
        }
    }
    ctx->pc = 0x18B118u;
    // 0x18b118: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x18B118u;
    {
        const bool branch_taken_0x18b118 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x18b118) {
            ctx->pc = 0x18B128u;
            goto label_18b128;
        }
    }
    ctx->pc = 0x18B120u;
    // 0x18b120: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x18B120u;
    {
        const bool branch_taken_0x18b120 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18B124u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B120u;
            // 0x18b124: 0x8fa30140  lw          $v1, 0x140($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 320)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b120) {
            ctx->pc = 0x18B13Cu;
            goto label_18b13c;
        }
    }
    ctx->pc = 0x18B128u;
label_18b128:
    // 0x18b128: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x18B128u;
    {
        const bool branch_taken_0x18b128 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18B12Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B128u;
            // 0x18b12c: 0xac440000  sw          $a0, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b128) {
            ctx->pc = 0x18B138u;
            goto label_18b138;
        }
    }
    ctx->pc = 0x18B130u;
label_18b130:
    // 0x18b130: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x18b130u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x18b134: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x18b134u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
label_18b138:
    // 0x18b138: 0x8fa30140  lw          $v1, 0x140($sp)
    ctx->pc = 0x18b138u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 320)));
label_18b13c:
    // 0x18b13c: 0x26650002  addiu       $a1, $s3, 0x2
    ctx->pc = 0x18b13cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
    // 0x18b140: 0x13303c  dsll32      $a2, $s3, 0
    ctx->pc = 0x18b140u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 19) << (32 + 0));
    // 0x18b144: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x18b144u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b148: 0x6303f  dsra32      $a2, $a2, 0
    ctx->pc = 0x18b148u;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 0));
    // 0x18b14c: 0x653818  mult        $a3, $v1, $a1
    ctx->pc = 0x18b14cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 7, (int32_t)result); }
    // 0x18b150: 0x24054000  addiu       $a1, $zero, 0x4000
    ctx->pc = 0x18b150u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x18b154: 0x34038000  ori         $v1, $zero, 0x8000
    ctx->pc = 0x18b154u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x18b158: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x18b158u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x18b15c: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x18b15cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x18b160: 0xc32825  or          $a1, $a2, $v1
    ctx->pc = 0x18b160u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x18b164: 0xdfa30130  ld          $v1, 0x130($sp)
    ctx->pc = 0x18b164u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x18b168: 0x73102  srl         $a2, $a3, 4
    ctx->pc = 0x18b168u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 7), 4));
    // 0x18b16c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x18b16cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x18b170: 0xa32825  or          $a1, $a1, $v1
    ctx->pc = 0x18b170u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x18b174: 0xdfa30120  ld          $v1, 0x120($sp)
    ctx->pc = 0x18b174u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 29), 288)));
    // 0x18b178: 0xac460004  sw          $a2, 0x4($v0)
    ctx->pc = 0x18b178u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 6));
    // 0x18b17c: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x18b17cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x18b180: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x18b180u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x18b184: 0xfc430010  sd          $v1, 0x10($v0)
    ctx->pc = 0x18b184u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 16), GPR_U64(ctx, 3));
    // 0x18b188: 0x8fa301a0  lw          $v1, 0x1A0($sp)
    ctx->pc = 0x18b188u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 416)));
    // 0x18b18c: 0xac430018  sw          $v1, 0x18($v0)
    ctx->pc = 0x18b18cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 3));
    // 0x18b190: 0xc0631fc  jal         func_18C7F0
    ctx->pc = 0x18B190u;
    SET_GPR_U32(ctx, 31, 0x18B198u);
    ctx->pc = 0x18B194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B190u;
            // 0x18b194: 0xac40001c  sw          $zero, 0x1C($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C7F0u;
    if (runtime->hasFunction(0x18C7F0u)) {
        auto targetFn = runtime->lookupFunction(0x18C7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B198u; }
        if (ctx->pc != 0x18B198u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7F0_0x18c7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B198u; }
        if (ctx->pc != 0x18B198u) { return; }
    }
    ctx->pc = 0x18B198u;
label_18b198:
    // 0x18b198: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x18b198u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_18b19c:
    // 0x18b19c: 0x8fa20230  lw          $v0, 0x230($sp)
    ctx->pc = 0x18b19cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 560)));
    // 0x18b1a0: 0x28080  sll         $s0, $v0, 2
    ctx->pc = 0x18b1a0u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x18b1a4: 0x21d1021  addu        $v0, $s0, $sp
    ctx->pc = 0x18b1a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 29)));
    // 0x18b1a8: 0x8c440270  lw          $a0, 0x270($v0)
    ctx->pc = 0x18b1a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 624)));
    // 0x18b1ac: 0x1684000d  bne         $s4, $a0, . + 4 + (0xD << 2)
    ctx->pc = 0x18B1ACu;
    {
        const bool branch_taken_0x18b1ac = (GPR_U64(ctx, 20) != GPR_U64(ctx, 4));
        ctx->pc = 0x18B1B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B1ACu;
            // 0x18b1b0: 0x2b41023  subu        $v0, $s5, $s4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b1ac) {
            ctx->pc = 0x18B1E4u;
            goto label_18b1e4;
        }
    }
    ctx->pc = 0x18B1B4u;
    // 0x18b1b4: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x18b1b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b1b8: 0x21102  srl         $v0, $v0, 4
    ctx->pc = 0x18b1b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
    // 0x18b1bc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x18b1bcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b1c0: 0x2445ffff  addiu       $a1, $v0, -0x1
    ctx->pc = 0x18b1c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x18b1c4: 0xc0631e4  jal         func_18C790
    ctx->pc = 0x18B1C4u;
    SET_GPR_U32(ctx, 31, 0x18B1CCu);
    ctx->pc = 0x18B1C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B1C4u;
            // 0x18b1c8: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C790u;
    if (runtime->hasFunction(0x18C790u)) {
        auto targetFn = runtime->lookupFunction(0x18C790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B1CCu; }
        if (ctx->pc != 0x18B1CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C790_0x18c790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B1CCu; }
        if (ctx->pc != 0x18B1CCu) { return; }
    }
    ctx->pc = 0x18B1CCu;
label_18b1cc:
    // 0x18b1cc: 0x8fa301b0  lw          $v1, 0x1B0($sp)
    ctx->pc = 0x18b1ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 432)));
    // 0x18b1d0: 0x702021  addu        $a0, $v1, $s0
    ctx->pc = 0x18b1d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x18b1d4: 0x8fa3024c  lw          $v1, 0x24C($sp)
    ctx->pc = 0x18b1d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 588)));
    // 0x18b1d8: 0x2831823  subu        $v1, $s4, $v1
    ctx->pc = 0x18b1d8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
    // 0x18b1dc: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x18B1DCu;
    {
        const bool branch_taken_0x18b1dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18B1E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B1DCu;
            // 0x18b1e0: 0xac830000  sw          $v1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b1dc) {
            ctx->pc = 0x18B264u;
            goto label_18b264;
        }
    }
    ctx->pc = 0x18B1E4u;
label_18b1e4:
    // 0x18b1e4: 0x8c850000  lw          $a1, 0x0($a0)
    ctx->pc = 0x18b1e4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18b1e8: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x18b1e8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x18b1ec: 0x3c026000  lui         $v0, 0x6000
    ctx->pc = 0x18b1ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)24576 << 16));
    // 0x18b1f0: 0xa31824  and         $v1, $a1, $v1
    ctx->pc = 0x18b1f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x18b1f4: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x18B1F4u;
    {
        const bool branch_taken_0x18b1f4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x18B1F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B1F4u;
            // 0x18b1f8: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b1f4) {
            ctx->pc = 0x18B22Cu;
            goto label_18b22c;
        }
    }
    ctx->pc = 0x18B1FCu;
    // 0x18b1fc: 0x10620006  beq         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x18B1FCu;
    {
        const bool branch_taken_0x18b1fc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x18b1fc) {
            ctx->pc = 0x18B218u;
            goto label_18b218;
        }
    }
    ctx->pc = 0x18B204u;
    // 0x18b204: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x18b204u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x18b208: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18B208u;
    {
        const bool branch_taken_0x18b208 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x18B20Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B208u;
            // 0x18b20c: 0x30a2ffff  andi        $v0, $a1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b208) {
            ctx->pc = 0x18B21Cu;
            goto label_18b21c;
        }
    }
    ctx->pc = 0x18B210u;
    // 0x18b210: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x18B210u;
    {
        const bool branch_taken_0x18b210 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18b210) {
            ctx->pc = 0x18B244u;
            goto label_18b244;
        }
    }
    ctx->pc = 0x18B218u;
label_18b218:
    // 0x18b218: 0x30a2ffff  andi        $v0, $a1, 0xFFFF
    ctx->pc = 0x18b218u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
label_18b21c:
    // 0x18b21c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x18b21cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x18b220: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x18b220u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x18b224: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x18B224u;
    {
        const bool branch_taken_0x18b224 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18B228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B224u;
            // 0x18b228: 0x822021  addu        $a0, $a0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b224) {
            ctx->pc = 0x18B244u;
            goto label_18b244;
        }
    }
    ctx->pc = 0x18B22Cu;
label_18b22c:
    // 0x18b22c: 0x30a5ffff  andi        $a1, $a1, 0xFFFF
    ctx->pc = 0x18b22cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x18b230: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x18b230u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b234: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x18b234u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b238: 0xc063188  jal         func_18C620
    ctx->pc = 0x18B238u;
    SET_GPR_U32(ctx, 31, 0x18B240u);
    ctx->pc = 0x18B23Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B238u;
            // 0x18b23c: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C620u;
    if (runtime->hasFunction(0x18C620u)) {
        auto targetFn = runtime->lookupFunction(0x18C620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B240u; }
        if (ctx->pc != 0x18B240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C620_0x18c620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B240u; }
        if (ctx->pc != 0x18B240u) { return; }
    }
    ctx->pc = 0x18B240u;
label_18b240:
    // 0x18b240: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x18b240u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18b244:
    // 0x18b244: 0x1480ffe7  bnez        $a0, . + 4 + (-0x19 << 2)
    ctx->pc = 0x18B244u;
    {
        const bool branch_taken_0x18b244 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x18B248u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B244u;
            // 0x18b248: 0x2b41023  subu        $v0, $s5, $s4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b244) {
            ctx->pc = 0x18B1E4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18b1e4;
        }
    }
    ctx->pc = 0x18B24Cu;
    // 0x18b24c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x18b24cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b250: 0x21102  srl         $v0, $v0, 4
    ctx->pc = 0x18b250u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
    // 0x18b254: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x18b254u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b258: 0x2445ffff  addiu       $a1, $v0, -0x1
    ctx->pc = 0x18b258u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x18b25c: 0xc0631e4  jal         func_18C790
    ctx->pc = 0x18B25Cu;
    SET_GPR_U32(ctx, 31, 0x18B264u);
    ctx->pc = 0x18B260u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B25Cu;
            // 0x18b260: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C790u;
    if (runtime->hasFunction(0x18C790u)) {
        auto targetFn = runtime->lookupFunction(0x18C790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B264u; }
        if (ctx->pc != 0x18B264u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C790_0x18c790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B264u; }
        if (ctx->pc != 0x18B264u) { return; }
    }
    ctx->pc = 0x18B264u;
label_18b264:
    // 0x18b264: 0x8fa3024c  lw          $v1, 0x24C($sp)
    ctx->pc = 0x18b264u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 588)));
    // 0x18b268: 0x8fc70018  lw          $a3, 0x18($fp)
    ctx->pc = 0x18b268u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x18b26c: 0x2a31823  subu        $v1, $s5, $v1
    ctx->pc = 0x18b26cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 3)));
    // 0x18b270: 0x10e30006  beq         $a3, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x18B270u;
    {
        const bool branch_taken_0x18b270 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 3));
        if (branch_taken_0x18b270) {
            ctx->pc = 0x18B28Cu;
            goto label_18b28c;
        }
    }
    ctx->pc = 0x18B278u;
    // 0x18b278: 0x8fa5024c  lw          $a1, 0x24C($sp)
    ctx->pc = 0x18b278u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 588)));
    // 0x18b27c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x18b27cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x18b280: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x18b280u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b284: 0xc0682b4  jal         func_1A0AD0
    ctx->pc = 0x18B284u;
    SET_GPR_U32(ctx, 31, 0x18B28Cu);
    ctx->pc = 0x18B288u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B284u;
            // 0x18b288: 0x24841b80  addiu       $a0, $a0, 0x1B80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7040));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A0AD0u;
    if (runtime->hasFunction(0x1A0AD0u)) {
        auto targetFn = runtime->lookupFunction(0x1A0AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B28Cu; }
        if (ctx->pc != 0x18B28Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A0AD0_0x1a0ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B28Cu; }
        if (ctx->pc != 0x18B28Cu) { return; }
    }
    ctx->pc = 0x18B28Cu;
label_18b28c:
    // 0x18b28c: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x18b28cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x18b290: 0x7bbe0080  lq          $fp, 0x80($sp)
    ctx->pc = 0x18b290u;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x18b294: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x18b294u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x18b298: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x18b298u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x18b29c: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x18b29cu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x18b2a0: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x18b2a0u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x18b2a4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x18b2a4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18b2a8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x18b2a8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18b2ac: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x18b2acu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18b2b0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18b2b0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18b2b4: 0x3e00008  jr          $ra
    ctx->pc = 0x18B2B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18B2B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B2B4u;
            // 0x18b2b8: 0x27bd0310  addiu       $sp, $sp, 0x310 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 784));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18A2C8u: goto label_18a2c8;
            case 0x18A2E4u: goto label_18a2e4;
            case 0x18A2F0u: goto label_18a2f0;
            case 0x18A30Cu: goto label_18a30c;
            case 0x18A310u: goto label_18a310;
            case 0x18A394u: goto label_18a394;
            case 0x18A39Cu: goto label_18a39c;
            case 0x18A470u: goto label_18a470;
            case 0x18A4A0u: goto label_18a4a0;
            case 0x18A4BCu: goto label_18a4bc;
            case 0x18A4E8u: goto label_18a4e8;
            case 0x18A50Cu: goto label_18a50c;
            case 0x18A514u: goto label_18a514;
            case 0x18A51Cu: goto label_18a51c;
            case 0x18A520u: goto label_18a520;
            case 0x18A57Cu: goto label_18a57c;
            case 0x18A5B4u: goto label_18a5b4;
            case 0x18A5CCu: goto label_18a5cc;
            case 0x18A600u: goto label_18a600;
            case 0x18A604u: goto label_18a604;
            case 0x18A614u: goto label_18a614;
            case 0x18A628u: goto label_18a628;
            case 0x18A62Cu: goto label_18a62c;
            case 0x18A64Cu: goto label_18a64c;
            case 0x18A650u: goto label_18a650;
            case 0x18A680u: goto label_18a680;
            case 0x18A694u: goto label_18a694;
            case 0x18A6C0u: goto label_18a6c0;
            case 0x18A6E0u: goto label_18a6e0;
            case 0x18A6E8u: goto label_18a6e8;
            case 0x18A6F0u: goto label_18a6f0;
            case 0x18A6F4u: goto label_18a6f4;
            case 0x18A750u: goto label_18a750;
            case 0x18A788u: goto label_18a788;
            case 0x18A794u: goto label_18a794;
            case 0x18A7ACu: goto label_18a7ac;
            case 0x18A7C0u: goto label_18a7c0;
            case 0x18A80Cu: goto label_18a80c;
            case 0x18A82Cu: goto label_18a82c;
            case 0x18A834u: goto label_18a834;
            case 0x18A83Cu: goto label_18a83c;
            case 0x18A840u: goto label_18a840;
            case 0x18A89Cu: goto label_18a89c;
            case 0x18A8D4u: goto label_18a8d4;
            case 0x18A8E0u: goto label_18a8e0;
            case 0x18A8F0u: goto label_18a8f0;
            case 0x18A930u: goto label_18a930;
            case 0x18A968u: goto label_18a968;
            case 0x18A96Cu: goto label_18a96c;
            case 0x18A9A8u: goto label_18a9a8;
            case 0x18A9ACu: goto label_18a9ac;
            case 0x18A9B0u: goto label_18a9b0;
            case 0x18A9ECu: goto label_18a9ec;
            case 0x18A9F0u: goto label_18a9f0;
            case 0x18A9F4u: goto label_18a9f4;
            case 0x18AA30u: goto label_18aa30;
            case 0x18AA48u: goto label_18aa48;
            case 0x18AA6Cu: goto label_18aa6c;
            case 0x18AA84u: goto label_18aa84;
            case 0x18AAA0u: goto label_18aaa0;
            case 0x18AAB8u: goto label_18aab8;
            case 0x18AAC0u: goto label_18aac0;
            case 0x18AAD4u: goto label_18aad4;
            case 0x18AAECu: goto label_18aaec;
            case 0x18AAFCu: goto label_18aafc;
            case 0x18AB00u: goto label_18ab00;
            case 0x18AB14u: goto label_18ab14;
            case 0x18AB20u: goto label_18ab20;
            case 0x18AB58u: goto label_18ab58;
            case 0x18AB5Cu: goto label_18ab5c;
            case 0x18AB98u: goto label_18ab98;
            case 0x18AB9Cu: goto label_18ab9c;
            case 0x18ABA0u: goto label_18aba0;
            case 0x18ABDCu: goto label_18abdc;
            case 0x18ABE0u: goto label_18abe0;
            case 0x18ABE4u: goto label_18abe4;
            case 0x18AC14u: goto label_18ac14;
            case 0x18AC2Cu: goto label_18ac2c;
            case 0x18AC3Cu: goto label_18ac3c;
            case 0x18AC44u: goto label_18ac44;
            case 0x18AC58u: goto label_18ac58;
            case 0x18AC70u: goto label_18ac70;
            case 0x18AC80u: goto label_18ac80;
            case 0x18AC84u: goto label_18ac84;
            case 0x18AC98u: goto label_18ac98;
            case 0x18ACA0u: goto label_18aca0;
            case 0x18AD08u: goto label_18ad08;
            case 0x18AD48u: goto label_18ad48;
            case 0x18AD4Cu: goto label_18ad4c;
            case 0x18AD88u: goto label_18ad88;
            case 0x18AD8Cu: goto label_18ad8c;
            case 0x18AD90u: goto label_18ad90;
            case 0x18ADCCu: goto label_18adcc;
            case 0x18ADD0u: goto label_18add0;
            case 0x18ADD4u: goto label_18add4;
            case 0x18AE04u: goto label_18ae04;
            case 0x18AE1Cu: goto label_18ae1c;
            case 0x18AE2Cu: goto label_18ae2c;
            case 0x18AE34u: goto label_18ae34;
            case 0x18AE48u: goto label_18ae48;
            case 0x18AE60u: goto label_18ae60;
            case 0x18AE70u: goto label_18ae70;
            case 0x18AE74u: goto label_18ae74;
            case 0x18AE88u: goto label_18ae88;
            case 0x18AE90u: goto label_18ae90;
            case 0x18AEF4u: goto label_18aef4;
            case 0x18AFC4u: goto label_18afc4;
            case 0x18B02Cu: goto label_18b02c;
            case 0x18B038u: goto label_18b038;
            case 0x18B0A0u: goto label_18b0a0;
            case 0x18B0A4u: goto label_18b0a4;
            case 0x18B0B8u: goto label_18b0b8;
            case 0x18B0D8u: goto label_18b0d8;
            case 0x18B108u: goto label_18b108;
            case 0x18B128u: goto label_18b128;
            case 0x18B130u: goto label_18b130;
            case 0x18B138u: goto label_18b138;
            case 0x18B13Cu: goto label_18b13c;
            case 0x18B198u: goto label_18b198;
            case 0x18B19Cu: goto label_18b19c;
            case 0x18B1CCu: goto label_18b1cc;
            case 0x18B1E4u: goto label_18b1e4;
            case 0x18B218u: goto label_18b218;
            case 0x18B21Cu: goto label_18b21c;
            case 0x18B22Cu: goto label_18b22c;
            case 0x18B240u: goto label_18b240;
            case 0x18B244u: goto label_18b244;
            case 0x18B264u: goto label_18b264;
            case 0x18B28Cu: goto label_18b28c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18B2BCu;
    // 0x18b2bc: 0x0  nop
    ctx->pc = 0x18b2bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
