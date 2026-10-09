#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CE570
// Address: 0x1ce570 - 0x1ce700
void sub_001CE570_0x1ce570(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CE570_0x1ce570");
#endif

    switch (ctx->pc) {
        case 0x1ce5a8u: goto label_1ce5a8;
        case 0x1ce5bcu: goto label_1ce5bc;
        case 0x1ce5f4u: goto label_1ce5f4;
        case 0x1ce604u: goto label_1ce604;
        case 0x1ce614u: goto label_1ce614;
        case 0x1ce648u: goto label_1ce648;
        case 0x1ce690u: goto label_1ce690;
        case 0x1ce6acu: goto label_1ce6ac;
        case 0x1ce6c0u: goto label_1ce6c0;
        default: break;
    }

    ctx->pc = 0x1ce570u;

    // 0x1ce570: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1ce570u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1ce574: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ce574u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce578: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1ce578u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1ce57c: 0x24060140  addiu       $a2, $zero, 0x140
    ctx->pc = 0x1ce57cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 320));
    // 0x1ce580: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1ce580u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1ce584: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1ce584u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1ce588: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x1ce588u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce58c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1ce58cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1ce590: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1ce590u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1ce594: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1ce594u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ce598: 0x24841500  addiu       $a0, $a0, 0x1500
    ctx->pc = 0x1ce598u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5376));
    // 0x1ce59c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ce59cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ce5a0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CE5A0u;
    SET_GPR_U32(ctx, 31, 0x1CE5A8u);
    ctx->pc = 0x1CE5A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE5A0u;
            // 0x1ce5a4: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE5A8u; }
        if (ctx->pc != 0x1CE5A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE5A8u; }
        if (ctx->pc != 0x1CE5A8u) { return; }
    }
    ctx->pc = 0x1CE5A8u;
label_1ce5a8:
    // 0x1ce5a8: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1ce5a8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1ce5ac: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ce5acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce5b0: 0x24841430  addiu       $a0, $a0, 0x1430
    ctx->pc = 0x1ce5b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5168));
    // 0x1ce5b4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CE5B4u;
    SET_GPR_U32(ctx, 31, 0x1CE5BCu);
    ctx->pc = 0x1CE5B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE5B4u;
            // 0x1ce5b8: 0x240600c0  addiu       $a2, $zero, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE5BCu; }
        if (ctx->pc != 0x1CE5BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE5BCu; }
        if (ctx->pc != 0x1CE5BCu) { return; }
    }
    ctx->pc = 0x1CE5BCu;
label_1ce5bc:
    // 0x1ce5bc: 0x8ea30014  lw          $v1, 0x14($s5)
    ctx->pc = 0x1ce5bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 20)));
    // 0x1ce5c0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ce5c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ce5c4: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1ce5c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1ce5c8: 0x3c130034  lui         $s3, 0x34
    ctx->pc = 0x1ce5c8u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)52 << 16));
    // 0x1ce5cc: 0x3c120034  lui         $s2, 0x34
    ctx->pc = 0x1ce5ccu;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)52 << 16));
    // 0x1ce5d0: 0x34424680  ori         $v0, $v0, 0x4680
    ctx->pc = 0x1ce5d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)18048);
    // 0x1ce5d4: 0x26731430  addiu       $s3, $s3, 0x1430
    ctx->pc = 0x1ce5d4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 5168));
    // 0x1ce5d8: 0x26521500  addiu       $s2, $s2, 0x1500
    ctx->pc = 0x1ce5d8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 5376));
    // 0x1ce5dc: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x1ce5dcu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce5e0: 0xac2314f0  sw          $v1, 0x14F0($at)
    ctx->pc = 0x1ce5e0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 5360), GPR_U32(ctx, 3));
    // 0x1ce5e4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ce5e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ce5e8: 0x8ea30014  lw          $v1, 0x14($s5)
    ctx->pc = 0x1ce5e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 20)));
    // 0x1ce5ec: 0x8c3114f0  lw          $s1, 0x14F0($at)
    ctx->pc = 0x1ce5ecu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5360)));
    // 0x1ce5f0: 0x628021  addu        $s0, $v1, $v0
    ctx->pc = 0x1ce5f0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_1ce5f4:
    // 0x1ce5f4: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1ce5f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce5f8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ce5f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce5fc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CE5FCu;
    SET_GPR_U32(ctx, 31, 0x1CE604u);
    ctx->pc = 0x1CE600u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE5FCu;
            // 0x1ce600: 0x2406000c  addiu       $a2, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE604u; }
        if (ctx->pc != 0x1CE604u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE604u; }
        if (ctx->pc != 0x1CE604u) { return; }
    }
    ctx->pc = 0x1CE604u;
label_1ce604:
    // 0x1ce604: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1ce604u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce608: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ce608u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce60c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CE60Cu;
    SET_GPR_U32(ctx, 31, 0x1CE614u);
    ctx->pc = 0x1CE610u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE60Cu;
            // 0x1ce610: 0x24061468  addiu       $a2, $zero, 0x1468 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 5224));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE614u; }
        if (ctx->pc != 0x1CE614u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE614u; }
        if (ctx->pc != 0x1CE614u) { return; }
    }
    ctx->pc = 0x1CE614u;
label_1ce614:
    // 0x1ce614: 0x26220820  addiu       $v0, $s1, 0x820
    ctx->pc = 0x1ce614u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 2080));
    // 0x1ce618: 0x26230a20  addiu       $v1, $s1, 0xA20
    ctx->pc = 0x1ce618u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 2592));
    // 0x1ce61c: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1ce61cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1ce620: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1ce620u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce624: 0x26220c20  addiu       $v0, $s1, 0xC20
    ctx->pc = 0x1ce624u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 3104));
    // 0x1ce628: 0xae230004  sw          $v1, 0x4($s1)
    ctx->pc = 0x1ce628u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
    // 0x1ce62c: 0xae220818  sw          $v0, 0x818($s1)
    ctx->pc = 0x1ce62cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2072), GPR_U32(ctx, 2));
    // 0x1ce630: 0xae300808  sw          $s0, 0x808($s1)
    ctx->pc = 0x1ce630u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2056), GPR_U32(ctx, 16));
    // 0x1ce634: 0xa2740001  sb          $s4, 0x1($s3)
    ctx->pc = 0x1ce634u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 1), (uint8_t)GPR_U32(ctx, 20));
    // 0x1ce638: 0x26101300  addiu       $s0, $s0, 0x1300
    ctx->pc = 0x1ce638u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4864));
    // 0x1ce63c: 0xae710004  sw          $s1, 0x4($s3)
    ctx->pc = 0x1ce63cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 17));
    // 0x1ce640: 0xa254000e  sb          $s4, 0xE($s2)
    ctx->pc = 0x1ce640u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 14), (uint8_t)GPR_U32(ctx, 20));
    // 0x1ce644: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1ce644u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1ce648:
    // 0x1ce648: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x1ce648u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1ce64c: 0x2421021  addu        $v0, $s2, $v0
    ctx->pc = 0x1ce64cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x1ce650: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1ce650u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1ce654: 0xa4430002  sh          $v1, 0x2($v0)
    ctx->pc = 0x1ce654u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 2), (uint16_t)GPR_U32(ctx, 3));
    // 0x1ce658: 0x28820006  slti        $v0, $a0, 0x6
    ctx->pc = 0x1ce658u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)6) ? 1 : 0);
    // 0x1ce65c: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1CE65Cu;
    {
        const bool branch_taken_0x1ce65c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ce65c) {
            ctx->pc = 0x1CE648u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ce648;
        }
    }
    ctx->pc = 0x1CE664u;
    // 0x1ce664: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x1ce664u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x1ce668: 0x2673000c  addiu       $s3, $s3, 0xC
    ctx->pc = 0x1ce668u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 12));
    // 0x1ce66c: 0x2a820010  slti        $v0, $s4, 0x10
    ctx->pc = 0x1ce66cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1ce670: 0x26311468  addiu       $s1, $s1, 0x1468
    ctx->pc = 0x1ce670u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 5224));
    // 0x1ce674: 0x1440ffdf  bnez        $v0, . + 4 + (-0x21 << 2)
    ctx->pc = 0x1CE674u;
    {
        const bool branch_taken_0x1ce674 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CE678u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE674u;
            // 0x1ce678: 0x26520014  addiu       $s2, $s2, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ce674) {
            ctx->pc = 0x1CE5F4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ce5f4;
        }
    }
    ctx->pc = 0x1CE67Cu;
    // 0x1ce67c: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1ce67cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1ce680: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ce680u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce684: 0x248413f0  addiu       $a0, $a0, 0x13F0
    ctx->pc = 0x1ce684u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5104));
    // 0x1ce688: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CE688u;
    SET_GPR_U32(ctx, 31, 0x1CE690u);
    ctx->pc = 0x1CE68Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE688u;
            // 0x1ce68c: 0x24060040  addiu       $a2, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE690u; }
        if (ctx->pc != 0x1CE690u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE690u; }
        if (ctx->pc != 0x1CE690u) { return; }
    }
    ctx->pc = 0x1CE690u;
label_1ce690:
    // 0x1ce690: 0x8ea30014  lw          $v1, 0x14($s5)
    ctx->pc = 0x1ce690u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 20)));
    // 0x1ce694: 0x3c020002  lui         $v0, 0x2
    ctx->pc = 0x1ce694u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)2 << 16));
    // 0x1ce698: 0x34427680  ori         $v0, $v0, 0x7680
    ctx->pc = 0x1ce698u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)30336);
    // 0x1ce69c: 0x3c110034  lui         $s1, 0x34
    ctx->pc = 0x1ce69cu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)52 << 16));
    // 0x1ce6a0: 0x263113f0  addiu       $s1, $s1, 0x13F0
    ctx->pc = 0x1ce6a0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 5104));
    // 0x1ce6a4: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1ce6a4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce6a8: 0x629021  addu        $s2, $v1, $v0
    ctx->pc = 0x1ce6a8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_1ce6ac:
    // 0x1ce6ac: 0xae320004  sw          $s2, 0x4($s1)
    ctx->pc = 0x1ce6acu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 18));
    // 0x1ce6b0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ce6b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce6b4: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x1ce6b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1ce6b8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CE6B8u;
    SET_GPR_U32(ctx, 31, 0x1CE6C0u);
    ctx->pc = 0x1CE6BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE6B8u;
            // 0x1ce6bc: 0x24061000  addiu       $a2, $zero, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE6C0u; }
        if (ctx->pc != 0x1CE6C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE6C0u; }
        if (ctx->pc != 0x1CE6C0u) { return; }
    }
    ctx->pc = 0x1CE6C0u;
label_1ce6c0:
    // 0x1ce6c0: 0xa2300001  sb          $s0, 0x1($s1)
    ctx->pc = 0x1ce6c0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 16));
    // 0x1ce6c4: 0x26521000  addiu       $s2, $s2, 0x1000
    ctx->pc = 0x1ce6c4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4096));
    // 0x1ce6c8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1ce6c8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1ce6cc: 0x2a030004  slti        $v1, $s0, 0x4
    ctx->pc = 0x1ce6ccu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1ce6d0: 0x1460fff6  bnez        $v1, . + 4 + (-0xA << 2)
    ctx->pc = 0x1CE6D0u;
    {
        const bool branch_taken_0x1ce6d0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CE6D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE6D0u;
            // 0x1ce6d4: 0x26310010  addiu       $s1, $s1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ce6d0) {
            ctx->pc = 0x1CE6ACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ce6ac;
        }
    }
    ctx->pc = 0x1CE6D8u;
    // 0x1ce6d8: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1ce6d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1ce6dc: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1ce6dcu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1ce6e0: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1ce6e0u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1ce6e4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1ce6e4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ce6e8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1ce6e8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ce6ec: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ce6ecu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ce6f0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ce6f0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ce6f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1CE6F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CE6F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE6F4u;
            // 0x1ce6f8: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CE5A8u: goto label_1ce5a8;
            case 0x1CE5BCu: goto label_1ce5bc;
            case 0x1CE5F4u: goto label_1ce5f4;
            case 0x1CE604u: goto label_1ce604;
            case 0x1CE614u: goto label_1ce614;
            case 0x1CE648u: goto label_1ce648;
            case 0x1CE690u: goto label_1ce690;
            case 0x1CE6ACu: goto label_1ce6ac;
            case 0x1CE6C0u: goto label_1ce6c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CE6FCu;
    // 0x1ce6fc: 0x0  nop
    ctx->pc = 0x1ce6fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
