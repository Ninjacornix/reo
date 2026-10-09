#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00116920
// Address: 0x116920 - 0x116ba0
void sub_00116920_0x116920(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00116920_0x116920");
#endif

    switch (ctx->pc) {
        case 0x116940u: goto label_116940;
        case 0x1169d8u: goto label_1169d8;
        case 0x116a08u: goto label_116a08;
        case 0x116a54u: goto label_116a54;
        case 0x116a5cu: goto label_116a5c;
        case 0x116a9cu: goto label_116a9c;
        case 0x116ab0u: goto label_116ab0;
        case 0x116ac0u: goto label_116ac0;
        case 0x116accu: goto label_116acc;
        case 0x116b18u: goto label_116b18;
        case 0x116b20u: goto label_116b20;
        case 0x116b34u: goto label_116b34;
        case 0x116b44u: goto label_116b44;
        case 0x116b54u: goto label_116b54;
        default: break;
    }

    ctx->pc = 0x116920u;

    // 0x116920: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x116920u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x116924: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x116924u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x116928: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x116928u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x11692c: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x11692cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x116930: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x116930u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x116934: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x116934u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x116938: 0xc047598  jal         func_11D660
    ctx->pc = 0x116938u;
    SET_GPR_U32(ctx, 31, 0x116940u);
    ctx->pc = 0x11693Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116938u;
            // 0x11693c: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116940u; }
        if (ctx->pc != 0x116940u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116940u; }
        if (ctx->pc != 0x116940u) { return; }
    }
    ctx->pc = 0x116940u;
label_116940:
    // 0x116940: 0x3c0a0021  lui         $t2, 0x21
    ctx->pc = 0x116940u;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)33 << 16));
    // 0x116944: 0x8d429d48  lw          $v0, -0x62B8($t2)
    ctx->pc = 0x116944u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 4294942024)));
    // 0x116948: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x116948u;
    {
        const bool branch_taken_0x116948 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11694Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116948u;
            // 0x11694c: 0x3c130026  lui         $s3, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116948) {
            ctx->pc = 0x116970u;
            goto label_116970;
        }
    }
    ctx->pc = 0x116950u;
    // 0x116950: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x116950u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x116954: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x116954u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x116958: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x116958u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11695c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11695cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x116960: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x116960u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x116964: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x116964u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x116968: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x116968u;
    ctx->pc = 0x11696Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116968u;
            // 0x11696c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x116970u;
label_116970:
    // 0x116970: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x116970u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x116974: 0x3c022000  lui         $v0, 0x2000
    ctx->pc = 0x116974u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
    // 0x116978: 0x24a5af40  addiu       $a1, $a1, -0x50C0
    ctx->pc = 0x116978u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294946624));
    // 0x11697c: 0x2666aec0  addiu       $a2, $s3, -0x5140
    ctx->pc = 0x11697cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), 4294946496));
    // 0x116980: 0x3c120026  lui         $s2, 0x26
    ctx->pc = 0x116980u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)38 << 16));
    // 0x116984: 0xa22825  or          $a1, $a1, $v0
    ctx->pc = 0x116984u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x116988: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x116988u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x11698c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x11698cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x116990: 0x3c090026  lui         $t1, 0x26
    ctx->pc = 0x116990u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)38 << 16));
    // 0x116994: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x116994u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x116998: 0x2642af98  addiu       $v0, $s2, -0x5068
    ctx->pc = 0x116998u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4294946712));
    // 0x11699c: 0xad439d48  sw          $v1, -0x62B8($t2)
    ctx->pc = 0x11699cu;
    WRITE32(ADD32(GPR_U32(ctx, 10), 4294942024), GPR_U32(ctx, 3));
    // 0x1169a0: 0x2484b140  addiu       $a0, $a0, -0x4EC0
    ctx->pc = 0x1169a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947136));
    // 0x1169a4: 0x2528afc0  addiu       $t0, $t1, -0x5040
    ctx->pc = 0x1169a4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 9), 4294946752));
    // 0x1169a8: 0xae46af98  sw          $a2, -0x5068($s2)
    ctx->pc = 0x1169a8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4294946712), GPR_U32(ctx, 6));
    // 0x1169ac: 0x24070020  addiu       $a3, $zero, 0x20
    ctx->pc = 0x1169acu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1169b0: 0xac44001c  sw          $a0, 0x1C($v0)
    ctx->pc = 0x1169b0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 4));
    // 0x1169b4: 0x100182d  daddu       $v1, $t0, $zero
    ctx->pc = 0x1169b4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1169b8: 0xac450004  sw          $a1, 0x4($v0)
    ctx->pc = 0x1169b8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x1169bc: 0xac470010  sw          $a3, 0x10($v0)
    ctx->pc = 0x1169bcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 7));
    // 0x1169c0: 0x24640180  addiu       $a0, $v1, 0x180
    ctx->pc = 0x1169c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 384));
    // 0x1169c4: 0xac400008  sw          $zero, 0x8($v0)
    ctx->pc = 0x1169c4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 0));
    // 0x1169c8: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x1169c8u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
    // 0x1169cc: 0xac48000c  sw          $t0, 0xC($v0)
    ctx->pc = 0x1169ccu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 8));
    // 0x1169d0: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x1169d0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x1169d4: 0xac400018  sw          $zero, 0x18($v0)
    ctx->pc = 0x1169d4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 0));
label_1169d8:
    // 0x1169d8: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x1169d8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x1169dc: 0xac600004  sw          $zero, 0x4($v1)
    ctx->pc = 0x1169dcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 0));
    // 0x1169e0: 0x2463000c  addiu       $v1, $v1, 0xC
    ctx->pc = 0x1169e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 12));
    // 0x1169e4: 0x64102a  slt         $v0, $v1, $a0
    ctx->pc = 0x1169e4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1169e8: 0x0  nop
    ctx->pc = 0x1169e8u;
    // NOP
    // 0x1169ec: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1169ECu;
    {
        const bool branch_taken_0x1169ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1169ec) {
            ctx->pc = 0x1169D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1169d8;
        }
    }
    ctx->pc = 0x1169F4u;
    // 0x1169f4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1169f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1169f8: 0x2410001f  addiu       $s0, $zero, 0x1F
    ctx->pc = 0x1169f8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x1169fc: 0x2442b140  addiu       $v0, $v0, -0x4EC0
    ctx->pc = 0x1169fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294947136));
    // 0x116a00: 0x2442007c  addiu       $v0, $v0, 0x7C
    ctx->pc = 0x116a00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 124));
    // 0x116a04: 0x0  nop
    ctx->pc = 0x116a04u;
    // NOP
label_116a08:
    // 0x116a08: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x116a08u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x116a0c: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x116a0cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x116a10: 0x2442fffc  addiu       $v0, $v0, -0x4
    ctx->pc = 0x116a10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
    // 0x116a14: 0x0  nop
    ctx->pc = 0x116a14u;
    // NOP
    // 0x116a18: 0x0  nop
    ctx->pc = 0x116a18u;
    // NOP
    // 0x116a1c: 0x601fffa  bgez        $s0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x116A1Cu;
    {
        const bool branch_taken_0x116a1c = (GPR_S64(ctx, 16) >= 0);
        if (branch_taken_0x116a1c) {
            ctx->pc = 0x116A08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_116a08;
        }
    }
    ctx->pc = 0x116A24u;
    // 0x116a24: 0x3c020011  lui         $v0, 0x11
    ctx->pc = 0x116a24u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17 << 16));
    // 0x116a28: 0x3c030011  lui         $v1, 0x11
    ctx->pc = 0x116a28u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17 << 16));
    // 0x116a2c: 0x244268c8  addiu       $v0, $v0, 0x68C8
    ctx->pc = 0x116a2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26824));
    // 0x116a30: 0x2524afc0  addiu       $a0, $t1, -0x5040
    ctx->pc = 0x116a30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), 4294946752));
    // 0x116a34: 0x246368a8  addiu       $v1, $v1, 0x68A8
    ctx->pc = 0x116a34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 26792));
    // 0x116a38: 0x2651af98  addiu       $s1, $s2, -0x5068
    ctx->pc = 0x116a38u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), 4294946712));
    // 0x116a3c: 0xad22afc0  sw          $v0, -0x5040($t1)
    ctx->pc = 0x116a3cu;
    WRITE32(ADD32(GPR_U32(ctx, 9), 4294946752), GPR_U32(ctx, 2));
    // 0x116a40: 0x24100020  addiu       $s0, $zero, 0x20
    ctx->pc = 0x116a40u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x116a44: 0xac83000c  sw          $v1, 0xC($a0)
    ctx->pc = 0x116a44u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 3));
    // 0x116a48: 0xac910010  sw          $s1, 0x10($a0)
    ctx->pc = 0x116a48u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 17));
    // 0x116a4c: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x116A4Cu;
    SET_GPR_U32(ctx, 31, 0x116A54u);
    ctx->pc = 0x116A50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116A4Cu;
            // 0x116a50: 0xac910004  sw          $s1, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116A54u; }
        if (ctx->pc != 0x116A54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116A54u; }
        if (ctx->pc != 0x116A54u) { return; }
    }
    ctx->pc = 0x116A54u;
label_116a54:
    // 0x116a54: 0xc045228  jal         func_1148A0
    ctx->pc = 0x116A54u;
    SET_GPR_U32(ctx, 31, 0x116A5Cu);
    ctx->pc = 0x116A58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116A54u;
            // 0x116a58: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116A5Cu; }
        if (ctx->pc != 0x116A5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116A5Cu; }
        if (ctx->pc != 0x116A5Cu) { return; }
    }
    ctx->pc = 0x116A5Cu;
label_116a5c:
    // 0x116a5c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x116a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x116a60: 0x3442e010  ori         $v0, $v0, 0xE010
    ctx->pc = 0x116a60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)57360);
    // 0x116a64: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x116a64u;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x116a68: 0x30630020  andi        $v1, $v1, 0x20
    ctx->pc = 0x116a68u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)32);
    // 0x116a6c: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x116A6Cu;
    {
        const bool branch_taken_0x116a6c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x116A70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116A6Cu;
            // 0x116a70: 0x3c021000  lui         $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116a6c) {
            ctx->pc = 0x116A80u;
            goto label_116a80;
        }
    }
    ctx->pc = 0x116A74u;
    // 0x116a74: 0x3c011001  lui         $at, 0x1001
    ctx->pc = 0x116a74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4097 << 16));
    // 0x116a78: 0xac30e010  sw          $s0, -0x1FF0($at)
    ctx->pc = 0x116a78u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294959120), GPR_U32(ctx, 16)); // MMIO: 0x1000e010
    // 0x116a7c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x116a7cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
label_116a80:
    // 0x116a80: 0x3442c000  ori         $v0, $v0, 0xC000
    ctx->pc = 0x116a80u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49152);
    // 0x116a84: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x116a84u;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x116a88: 0x30630100  andi        $v1, $v1, 0x100
    ctx->pc = 0x116a88u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)256);
    // 0x116a8c: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x116A8Cu;
    {
        const bool branch_taken_0x116a8c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x116A90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116A8Cu;
            // 0x116a90: 0x3c050011  lui         $a1, 0x11 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)17 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116a8c) {
            ctx->pc = 0x116AA0u;
            goto label_116aa0;
        }
    }
    ctx->pc = 0x116A94u;
    // 0x116a94: 0xc045280  jal         func_114A00
    ctx->pc = 0x116A94u;
    SET_GPR_U32(ctx, 31, 0x116A9Cu);
    ctx->pc = 0x114A00u;
    if (runtime->hasFunction(0x114A00u)) {
        auto targetFn = runtime->lookupFunction(0x114A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116A9Cu; }
        if (ctx->pc != 0x116A9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A00_0x114a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116A9Cu; }
        if (ctx->pc != 0x116A9Cu) { return; }
    }
    ctx->pc = 0x116A9Cu;
label_116a9c:
    // 0x116a9c: 0x3c050011  lui         $a1, 0x11
    ctx->pc = 0x116a9cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)17 << 16));
label_116aa0:
    // 0x116aa0: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x116aa0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x116aa4: 0x24a56e88  addiu       $a1, $a1, 0x6E88
    ctx->pc = 0x116aa4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 28296));
    // 0x116aa8: 0xc0450cc  jal         func_114330
    ctx->pc = 0x116AA8u;
    SET_GPR_U32(ctx, 31, 0x116AB0u);
    ctx->pc = 0x116AACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116AA8u;
            // 0x116aac: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114330u;
    if (runtime->hasFunction(0x114330u)) {
        auto targetFn = runtime->lookupFunction(0x114330u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116AB0u; }
        if (ctx->pc != 0x116AB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114330_0x114330(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116AB0u; }
        if (ctx->pc != 0x116AB0u) { return; }
    }
    ctx->pc = 0x116AB0u;
label_116ab0:
    // 0x116ab0: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x116ab0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x116ab4: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x116ab4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x116ab8: 0xc04548e  jal         func_115238
    ctx->pc = 0x116AB8u;
    SET_GPR_U32(ctx, 31, 0x116AC0u);
    ctx->pc = 0x116ABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116AB8u;
            // 0x116abc: 0xac62af94  sw          $v0, -0x506C($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294946708), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115238u;
    if (runtime->hasFunction(0x115238u)) {
        auto targetFn = runtime->lookupFunction(0x115238u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116AC0u; }
        if (ctx->pc != 0x116AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115238_0x115238(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116AC0u; }
        if (ctx->pc != 0x116AC0u) { return; }
    }
    ctx->pc = 0x116AC0u;
label_116ac0:
    // 0x116ac0: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x116ac0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x116ac4: 0xc04528c  jal         func_114A30
    ctx->pc = 0x116AC4u;
    SET_GPR_U32(ctx, 31, 0x116ACCu);
    ctx->pc = 0x114A30u;
    if (runtime->hasFunction(0x114A30u)) {
        auto targetFn = runtime->lookupFunction(0x114A30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116ACCu; }
        if (ctx->pc != 0x116ACCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A30_0x114a30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116ACCu; }
        if (ctx->pc != 0x116ACCu) { return; }
    }
    ctx->pc = 0x116ACCu;
label_116acc:
    // 0x116acc: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x116ACCu;
    {
        const bool branch_taken_0x116acc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x116AD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116ACCu;
            // 0x116ad0: 0xae220008  sw          $v0, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116acc) {
            ctx->pc = 0x116B14u;
            goto label_116b14;
        }
    }
    ctx->pc = 0x116AD4u;
    // 0x116ad4: 0x2685af80  addiu       $a1, $s4, -0x5080
    ctx->pc = 0x116ad4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), 4294946688));
    // 0x116ad8: 0x2662aec0  addiu       $v0, $s3, -0x5140
    ctx->pc = 0x116ad8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 4294946496));
    // 0x116adc: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x116adcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x116ae0: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x116ae0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x116ae4: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x116ae4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x116ae8: 0x24060014  addiu       $a2, $zero, 0x14
    ctx->pc = 0x116ae8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x116aec: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x116aecu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x116af0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x116af0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116af4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x116af4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x116af8: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x116af8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116afc: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x116afcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x116b00: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x116b00u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116b04: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x116b04u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x116b08: 0xaca20010  sw          $v0, 0x10($a1)
    ctx->pc = 0x116b08u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 2));
    // 0x116b0c: 0x8045b82  j           func_116E08
    ctx->pc = 0x116B0Cu;
    ctx->pc = 0x116B10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116B0Cu;
            // 0x116b10: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116E08u;
    if (runtime->hasFunction(0x116E08u)) {
        auto targetFn = runtime->lookupFunction(0x116E08u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116E08_0x116e08(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x116B14u;
label_116b14:
    // 0x116b14: 0x3c100002  lui         $s0, 0x2
    ctx->pc = 0x116b14u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)2 << 16));
label_116b18:
    // 0x116b18: 0xc04528c  jal         func_114A30
    ctx->pc = 0x116B18u;
    SET_GPR_U32(ctx, 31, 0x116B20u);
    ctx->pc = 0x116B1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116B18u;
            // 0x116b1c: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A30u;
    if (runtime->hasFunction(0x114A30u)) {
        auto targetFn = runtime->lookupFunction(0x114A30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116B20u; }
        if (ctx->pc != 0x116B20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A30_0x114a30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116B20u; }
        if (ctx->pc != 0x116B20u) { return; }
    }
    ctx->pc = 0x116B20u;
label_116b20:
    // 0x116b20: 0x501024  and         $v0, $v0, $s0
    ctx->pc = 0x116b20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 16));
    // 0x116b24: 0x1040fffc  beqz        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x116B24u;
    {
        const bool branch_taken_0x116b24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x116B28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116B24u;
            // 0x116b28: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116b24) {
            ctx->pc = 0x116B18u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_116b18;
        }
    }
    ctx->pc = 0x116B2Cu;
    // 0x116b2c: 0xc04528c  jal         func_114A30
    ctx->pc = 0x116B2Cu;
    SET_GPR_U32(ctx, 31, 0x116B34u);
    ctx->pc = 0x116B30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116B2Cu;
            // 0x116b30: 0x2650af98  addiu       $s0, $s2, -0x5068 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 4294946712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A30u;
    if (runtime->hasFunction(0x114A30u)) {
        auto targetFn = runtime->lookupFunction(0x114A30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116B34u; }
        if (ctx->pc != 0x116B34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A30_0x114a30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116B34u; }
        if (ctx->pc != 0x116B34u) { return; }
    }
    ctx->pc = 0x116B34u;
label_116b34:
    // 0x116b34: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x116b34u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0x116b38: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x116b38u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x116b3c: 0xc045288  jal         func_114A20
    ctx->pc = 0x116B3Cu;
    SET_GPR_U32(ctx, 31, 0x116B44u);
    ctx->pc = 0x116B40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116B3Cu;
            // 0x116b40: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A20u;
    if (runtime->hasFunction(0x114A20u)) {
        auto targetFn = runtime->lookupFunction(0x114A20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116B44u; }
        if (ctx->pc != 0x116B44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A20_0x114a20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116B44u; }
        if (ctx->pc != 0x116B44u) { return; }
    }
    ctx->pc = 0x116B44u;
label_116b44:
    // 0x116b44: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x116b44u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x116b48: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x116b48u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116b4c: 0xc045288  jal         func_114A20
    ctx->pc = 0x116B4Cu;
    SET_GPR_U32(ctx, 31, 0x116B54u);
    ctx->pc = 0x116B50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116B4Cu;
            // 0x116b50: 0x34840001  ori         $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A20u;
    if (runtime->hasFunction(0x114A20u)) {
        auto targetFn = runtime->lookupFunction(0x114A20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116B54u; }
        if (ctx->pc != 0x116B54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A20_0x114a20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116B54u; }
        if (ctx->pc != 0x116B54u) { return; }
    }
    ctx->pc = 0x116B54u;
label_116b54:
    // 0x116b54: 0x2683af80  addiu       $v1, $s4, -0x5080
    ctx->pc = 0x116b54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), 4294946688));
    // 0x116b58: 0x2662aec0  addiu       $v0, $s3, -0x5140
    ctx->pc = 0x116b58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 4294946496));
    // 0x116b5c: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x116b5cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x116b60: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x116b60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x116b64: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x116b64u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x116b68: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x116b68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116b6c: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x116b6cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x116b70: 0x34840002  ori         $a0, $a0, 0x2
    ctx->pc = 0x116b70u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)2);
    // 0x116b74: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x116b74u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x116b78: 0x24060014  addiu       $a2, $zero, 0x14
    ctx->pc = 0x116b78u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x116b7c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x116b7cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x116b80: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x116b80u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116b84: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x116b84u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x116b88: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x116b88u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116b8c: 0xac620010  sw          $v0, 0x10($v1)
    ctx->pc = 0x116b8cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 2));
    // 0x116b90: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x116b90u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116b94: 0xac60000c  sw          $zero, 0xC($v1)
    ctx->pc = 0x116b94u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 0));
    // 0x116b98: 0x8045b82  j           func_116E08
    ctx->pc = 0x116B98u;
    ctx->pc = 0x116B9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116B98u;
            // 0x116b9c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116E08u;
    if (runtime->hasFunction(0x116E08u)) {
        auto targetFn = runtime->lookupFunction(0x116E08u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116E08_0x116e08(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x116BA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
