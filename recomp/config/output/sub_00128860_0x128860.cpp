#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00128860
// Address: 0x128860 - 0x128a60
void sub_00128860_0x128860(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00128860_0x128860");
#endif

    switch (ctx->pc) {
        case 0x1288d0u: goto label_1288d0;
        case 0x1288e0u: goto label_1288e0;
        case 0x128924u: goto label_128924;
        case 0x128948u: goto label_128948;
        case 0x128970u: goto label_128970;
        case 0x128998u: goto label_128998;
        case 0x1289b0u: goto label_1289b0;
        case 0x1289c8u: goto label_1289c8;
        case 0x128a10u: goto label_128a10;
        case 0x128a24u: goto label_128a24;
        default: break;
    }

    ctx->pc = 0x128860u;

    // 0x128860: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x128860u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x128864: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x128864u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x128868: 0x140a02d  daddu       $s4, $t2, $zero
    ctx->pc = 0x128868u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12886c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x12886cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x128870: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x128870u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128874: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x128874u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x128878: 0x120882d  daddu       $s1, $t1, $zero
    ctx->pc = 0x128878u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12887c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x12887cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x128880: 0x160902d  daddu       $s2, $t3, $zero
    ctx->pc = 0x128880u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128884: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x128884u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x128888: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x128888u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12888c: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x12888cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x128890: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x128890u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128894: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x128894u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x128898: 0xc0b02d  daddu       $s6, $a2, $zero
    ctx->pc = 0x128898u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12889c: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x12889cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x1288a0: 0x16800005  bnez        $s4, . + 4 + (0x5 << 2)
    ctx->pc = 0x1288A0u;
    {
        const bool branch_taken_0x1288a0 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 0));
        ctx->pc = 0x1288A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1288A0u;
            // 0x1288a4: 0xafa80000  sw          $t0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1288a0) {
            ctx->pc = 0x1288B8u;
            goto label_1288b8;
        }
    }
    ctx->pc = 0x1288A8u;
    // 0x1288a8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1288a8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1288ac: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1288ACu;
    {
        const bool branch_taken_0x1288ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1288B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1288ACu;
            // 0x1288b0: 0x24849cd0  addiu       $a0, $a0, -0x6330 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294941904));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1288ac) {
            ctx->pc = 0x1288C8u;
            goto label_1288c8;
        }
    }
    ctx->pc = 0x1288B4u;
    // 0x1288b4: 0x0  nop
    ctx->pc = 0x1288b4u;
    // NOP
label_1288b8:
    // 0x1288b8: 0x1e400007  bgtz        $s2, . + 4 + (0x7 << 2)
    ctx->pc = 0x1288B8u;
    {
        const bool branch_taken_0x1288b8 = (GPR_S64(ctx, 18) > 0);
        if (branch_taken_0x1288b8) {
            ctx->pc = 0x1288D8u;
            goto label_1288d8;
        }
    }
    ctx->pc = 0x1288C0u;
    // 0x1288c0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1288c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1288c4: 0x24849d00  addiu       $a0, $a0, -0x6300
    ctx->pc = 0x1288c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294941952));
label_1288c8:
    // 0x1288c8: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x1288C8u;
    SET_GPR_U32(ctx, 31, 0x1288D0u);
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1288D0u; }
        if (ctx->pc != 0x1288D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1288D0u; }
        if (ctx->pc != 0x1288D0u) { return; }
    }
    ctx->pc = 0x1288D0u;
label_1288d0:
    // 0x1288d0: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x1288D0u;
    {
        const bool branch_taken_0x1288d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1288D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1288D0u;
            // 0x1288d4: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1288d0) {
            ctx->pc = 0x128A34u;
            goto label_128a34;
        }
    }
    ctx->pc = 0x1288D8u;
label_1288d8:
    // 0x1288d8: 0xc04a176  jal         func_1285D8
    ctx->pc = 0x1288D8u;
    SET_GPR_U32(ctx, 31, 0x1288E0u);
    ctx->pc = 0x1288DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1288D8u;
            // 0x1288dc: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1285D8u;
    if (runtime->hasFunction(0x1285D8u)) {
        auto targetFn = runtime->lookupFunction(0x1285D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1288E0u; }
        if (ctx->pc != 0x1288E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001285D8_0x1285d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1288E0u; }
        if (ctx->pc != 0x1288E0u) { return; }
    }
    ctx->pc = 0x1288E0u;
label_1288e0:
    // 0x1288e0: 0x4420055  bltzl       $v0, . + 4 + (0x55 << 2)
    ctx->pc = 0x1288E0u;
    {
        const bool branch_taken_0x1288e0 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1288e0) {
            ctx->pc = 0x1288E4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1288E0u;
            // 0x1288e4: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x128A38u;
            goto label_128a38;
        }
    }
    ctx->pc = 0x1288E8u;
    // 0x1288e8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1288e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1288ec: 0x2447d234  addiu       $a3, $v0, -0x2DCC
    ctx->pc = 0x1288ecu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 4294955572));
    // 0x1288f0: 0x8ce30000  lw          $v1, 0x0($a3)
    ctx->pc = 0x1288f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1288f4: 0x4600004  bltz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1288F4u;
    {
        const bool branch_taken_0x1288f4 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x1288F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1288F4u;
            // 0x1288f8: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1288f4) {
            ctx->pc = 0x128908u;
            goto label_128908;
        }
    }
    ctx->pc = 0x1288FCu;
    // 0x1288fc: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1288FCu;
    {
        const bool branch_taken_0x1288fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x128900u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1288FCu;
            // 0x128900: 0x24849d28  addiu       $a0, $a0, -0x62D8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294941992));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1288fc) {
            ctx->pc = 0x1289A8u;
            goto label_1289a8;
        }
    }
    ctx->pc = 0x128904u;
    // 0x128904: 0x0  nop
    ctx->pc = 0x128904u;
    // NOP
label_128908:
    // 0x128908: 0xacf30000  sw          $s3, 0x0($a3)
    ctx->pc = 0x128908u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 19));
    // 0x12890c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12890cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x128910: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x128910u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128914: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x128914u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128918: 0x2406011c  addiu       $a2, $zero, 0x11C
    ctx->pc = 0x128918u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 284));
    // 0x12891c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x12891Cu;
    SET_GPR_U32(ctx, 31, 0x128924u);
    ctx->pc = 0x128920u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12891Cu;
            // 0x128920: 0xac40d22c  sw          $zero, -0x2DD4($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294955564), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128924u; }
        if (ctx->pc != 0x128924u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128924u; }
        if (ctx->pc != 0x128924u) { return; }
    }
    ctx->pc = 0x128924u;
label_128924:
    // 0x128924: 0x131880  sll         $v1, $s3, 2
    ctx->pc = 0x128924u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
    // 0x128928: 0x3c010021  lui         $at, 0x21
    ctx->pc = 0x128928u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)33 << 16));
    // 0x12892c: 0x230821  addu        $at, $at, $v1
    ctx->pc = 0x12892cu;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x128930: 0xac31cd00  sw          $s1, -0x3300($at)
    ctx->pc = 0x128930u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294954240), GPR_U32(ctx, 17));
    // 0x128934: 0x16000014  bnez        $s0, . + 4 + (0x14 << 2)
    ctx->pc = 0x128934u;
    {
        const bool branch_taken_0x128934 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x128938u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128934u;
            // 0x128938: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128934) {
            ctx->pc = 0x128988u;
            goto label_128988;
        }
    }
    ctx->pc = 0x12893Cu;
    // 0x12893c: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x12893cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128940: 0xc04a490  jal         func_129240
    ctx->pc = 0x128940u;
    SET_GPR_U32(ctx, 31, 0x128948u);
    ctx->pc = 0x128944u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128940u;
            // 0x128944: 0x2c0282d  daddu       $a1, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129240u;
    if (runtime->hasFunction(0x129240u)) {
        auto targetFn = runtime->lookupFunction(0x129240u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128948u; }
        if (ctx->pc != 0x128948u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129240_0x129240(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128948u; }
        if (ctx->pc != 0x128948u) { return; }
    }
    ctx->pc = 0x128948u;
label_128948:
    // 0x128948: 0x3c130021  lui         $s3, 0x21
    ctx->pc = 0x128948u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)33 << 16));
    // 0x12894c: 0x10400014  beqz        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x12894Cu;
    {
        const bool branch_taken_0x12894c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x128950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12894Cu;
            // 0x128950: 0xae62d230  sw          $v0, -0x2DD0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4294955568), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12894c) {
            ctx->pc = 0x1289A0u;
            goto label_1289a0;
        }
    }
    ctx->pc = 0x128954u;
    // 0x128954: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x128954u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128958: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x128958u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12895c: 0x26260010  addiu       $a2, $s1, 0x10
    ctx->pc = 0x12895cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
    // 0x128960: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x128960u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128964: 0x27a80004  addiu       $t0, $sp, 0x4
    ctx->pc = 0x128964u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x128968: 0xc04a786  jal         func_129E18
    ctx->pc = 0x128968u;
    SET_GPR_U32(ctx, 31, 0x128970u);
    ctx->pc = 0x12896Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128968u;
            // 0x12896c: 0x27a90008  addiu       $t1, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129E18u;
    if (runtime->hasFunction(0x129E18u)) {
        auto targetFn = runtime->lookupFunction(0x129E18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128970u; }
        if (ctx->pc != 0x128970u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129E18_0x129e18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128970u; }
        if (ctx->pc != 0x128970u) { return; }
    }
    ctx->pc = 0x128970u;
label_128970:
    // 0x128970: 0x4420031  bltzl       $v0, . + 4 + (0x31 << 2)
    ctx->pc = 0x128970u;
    {
        const bool branch_taken_0x128970 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x128970) {
            ctx->pc = 0x128974u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x128970u;
            // 0x128974: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x128A38u;
            goto label_128a38;
        }
    }
    ctx->pc = 0x128978u;
    // 0x128978: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x128978u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x12897c: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x12897Cu;
    {
        const bool branch_taken_0x12897c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x128980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12897Cu;
            // 0x128980: 0xae220114  sw          $v0, 0x114($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 276), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12897c) {
            ctx->pc = 0x1289C8u;
            goto label_1289c8;
        }
    }
    ctx->pc = 0x128984u;
    // 0x128984: 0x0  nop
    ctx->pc = 0x128984u;
    // NOP
label_128988:
    // 0x128988: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x128988u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12898c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12898cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128990: 0xc04a432  jal         func_1290C8
    ctx->pc = 0x128990u;
    SET_GPR_U32(ctx, 31, 0x128998u);
    ctx->pc = 0x128994u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128990u;
            // 0x128994: 0x3c130021  lui         $s3, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1290C8u;
    if (runtime->hasFunction(0x1290C8u)) {
        auto targetFn = runtime->lookupFunction(0x1290C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128998u; }
        if (ctx->pc != 0x128998u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001290C8_0x1290c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128998u; }
        if (ctx->pc != 0x128998u) { return; }
    }
    ctx->pc = 0x128998u;
label_128998:
    // 0x128998: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x128998u;
    {
        const bool branch_taken_0x128998 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12899Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128998u;
            // 0x12899c: 0xae62d230  sw          $v0, -0x2DD0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4294955568), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128998) {
            ctx->pc = 0x1289B8u;
            goto label_1289b8;
        }
    }
    ctx->pc = 0x1289A0u;
label_1289a0:
    // 0x1289a0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1289a0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1289a4: 0x24849d58  addiu       $a0, $a0, -0x62A8
    ctx->pc = 0x1289a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942040));
label_1289a8:
    // 0x1289a8: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x1289A8u;
    SET_GPR_U32(ctx, 31, 0x1289B0u);
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1289B0u; }
        if (ctx->pc != 0x1289B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1289B0u; }
        if (ctx->pc != 0x1289B0u) { return; }
    }
    ctx->pc = 0x1289B0u;
label_1289b0:
    // 0x1289b0: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x1289B0u;
    {
        const bool branch_taken_0x1289b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1289B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1289B0u;
            // 0x1289b4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1289b0) {
            ctx->pc = 0x128A34u;
            goto label_128a34;
        }
    }
    ctx->pc = 0x1289B8u;
label_1289b8:
    // 0x1289b8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1289b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1289bc: 0x26240010  addiu       $a0, $s1, 0x10
    ctx->pc = 0x1289bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
    // 0x1289c0: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1289C0u;
    SET_GPR_U32(ctx, 31, 0x1289C8u);
    ctx->pc = 0x1289C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1289C0u;
            // 0x1289c4: 0x24060100  addiu       $a2, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1289C8u; }
        if (ctx->pc != 0x1289C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1289C8u; }
        if (ctx->pc != 0x1289C8u) { return; }
    }
    ctx->pc = 0x1289C8u;
label_1289c8:
    // 0x1289c8: 0x8fa20050  lw          $v0, 0x50($sp)
    ctx->pc = 0x1289c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1289cc: 0x264307ff  addiu       $v1, $s2, 0x7FF
    ctx->pc = 0x1289ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 2047));
    // 0x1289d0: 0xa220000e  sb          $zero, 0xE($s1)
    ctx->pc = 0x1289d0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 14), (uint8_t)GPR_U32(ctx, 0));
    // 0x1289d4: 0x2673d230  addiu       $s3, $s3, -0x2DD0
    ctx->pc = 0x1289d4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294955568));
    // 0x1289d8: 0xa222000f  sb          $v0, 0xF($s1)
    ctx->pc = 0x1289d8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 15), (uint8_t)GPR_U32(ctx, 2));
    // 0x1289dc: 0x2a420000  slti        $v0, $s2, 0x0
    ctx->pc = 0x1289dcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1289e0: 0x62900b  movn        $s2, $v1, $v0
    ctx->pc = 0x1289e0u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 18, GPR_VEC(ctx, 3));
    // 0x1289e4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1289e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1289e8: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x1289e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1289ec: 0x123ac3  sra         $a3, $s2, 11
    ctx->pc = 0x1289ecu;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 18), 11));
    // 0x1289f0: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x1289f0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x1289f4: 0xe0282d  daddu       $a1, $a3, $zero
    ctx->pc = 0x1289f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1289f8: 0xae240110  sw          $a0, 0x110($s1)
    ctx->pc = 0x1289f8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 272), GPR_U32(ctx, 4));
    // 0x1289fc: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x1289fcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128a00: 0x8e640000  lw          $a0, 0x0($s3)
    ctx->pc = 0x128a00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x128a04: 0xac54d238  sw          $s4, -0x2DC8($v0)
    ctx->pc = 0x128a04u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294955576), GPR_U32(ctx, 20));
    // 0x128a08: 0xc04a5e8  jal         func_1297A0
    ctx->pc = 0x128A08u;
    SET_GPR_U32(ctx, 31, 0x128A10u);
    ctx->pc = 0x128A0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128A08u;
            // 0x128a0c: 0xac67d23c  sw          $a3, -0x2DC4($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294955580), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1297A0u;
    if (runtime->hasFunction(0x1297A0u)) {
        auto targetFn = runtime->lookupFunction(0x1297A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128A10u; }
        if (ctx->pc != 0x128A10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001297A0_0x1297a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128A10u; }
        if (ctx->pc != 0x128A10u) { return; }
    }
    ctx->pc = 0x128A10u;
label_128a10:
    // 0x128a10: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x128a10u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128a14: 0x6030006  bgezl       $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x128A14u;
    {
        const bool branch_taken_0x128a14 = (GPR_S64(ctx, 16) >= 0);
        if (branch_taken_0x128a14) {
            ctx->pc = 0x128A18u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x128A14u;
            // 0x128a18: 0xae200008  sw          $zero, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x128A30u;
            goto label_128a30;
        }
    }
    ctx->pc = 0x128A1Cu;
    // 0x128a1c: 0xc04a4d4  jal         func_129350
    ctx->pc = 0x128A1Cu;
    SET_GPR_U32(ctx, 31, 0x128A24u);
    ctx->pc = 0x128A20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128A1Cu;
            // 0x128a20: 0x8e640000  lw          $a0, 0x0($s3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129350u;
    if (runtime->hasFunction(0x129350u)) {
        auto targetFn = runtime->lookupFunction(0x129350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128A24u; }
        if (ctx->pc != 0x128A24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129350_0x129350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128A24u; }
        if (ctx->pc != 0x128A24u) { return; }
    }
    ctx->pc = 0x128A24u;
label_128a24:
    // 0x128a24: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x128A24u;
    {
        const bool branch_taken_0x128a24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x128A28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128A24u;
            // 0x128a28: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128a24) {
            ctx->pc = 0x128A34u;
            goto label_128a34;
        }
    }
    ctx->pc = 0x128A2Cu;
    // 0x128a2c: 0x0  nop
    ctx->pc = 0x128a2cu;
    // NOP
label_128a30:
    // 0x128a30: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x128a30u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_128a34:
    // 0x128a34: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x128a34u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_128a38:
    // 0x128a38: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x128a38u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x128a3c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x128a3cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x128a40: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x128a40u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x128a44: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x128a44u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x128a48: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x128a48u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x128a4c: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x128a4cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x128a50: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x128a50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x128a54: 0x3e00008  jr          $ra
    ctx->pc = 0x128A54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x128A58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128A54u;
            // 0x128a58: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1288B8u: goto label_1288b8;
            case 0x1288C8u: goto label_1288c8;
            case 0x1288D0u: goto label_1288d0;
            case 0x1288D8u: goto label_1288d8;
            case 0x1288E0u: goto label_1288e0;
            case 0x128908u: goto label_128908;
            case 0x128924u: goto label_128924;
            case 0x128948u: goto label_128948;
            case 0x128970u: goto label_128970;
            case 0x128988u: goto label_128988;
            case 0x128998u: goto label_128998;
            case 0x1289A0u: goto label_1289a0;
            case 0x1289A8u: goto label_1289a8;
            case 0x1289B0u: goto label_1289b0;
            case 0x1289B8u: goto label_1289b8;
            case 0x1289C8u: goto label_1289c8;
            case 0x128A10u: goto label_128a10;
            case 0x128A24u: goto label_128a24;
            case 0x128A30u: goto label_128a30;
            case 0x128A34u: goto label_128a34;
            case 0x128A38u: goto label_128a38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x128A5Cu;
    // 0x128a5c: 0x0  nop
    ctx->pc = 0x128a5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
