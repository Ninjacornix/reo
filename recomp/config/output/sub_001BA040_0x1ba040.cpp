#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BA040
// Address: 0x1ba040 - 0x1ba164
void sub_001BA040_0x1ba040(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BA040_0x1ba040");
#endif

    switch (ctx->pc) {
        case 0x1ba068u: goto label_1ba068;
        case 0x1ba0b4u: goto label_1ba0b4;
        case 0x1ba0d4u: goto label_1ba0d4;
        case 0x1ba12cu: goto label_1ba12c;
        case 0x1ba150u: goto label_1ba150;
        default: break;
    }

    ctx->pc = 0x1ba040u;

    // 0x1ba040: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1ba040u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1ba044: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1ba044u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1ba048: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1ba048u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1ba04c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ba04cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ba050: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ba050u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ba054: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1ba054u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba058: 0x8c840024  lw          $a0, 0x24($a0)
    ctx->pc = 0x1ba058u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x1ba05c: 0x80304c11  lb          $s0, 0x4C11($at)
    ctx->pc = 0x1ba05cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 19473)));
    // 0x1ba060: 0xc06e65c  jal         func_1B9970
    ctx->pc = 0x1BA060u;
    SET_GPR_U32(ctx, 31, 0x1BA068u);
    ctx->pc = 0x1BA064u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA060u;
            // 0x1ba064: 0x27a50038  addiu       $a1, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B9970u;
    if (runtime->hasFunction(0x1B9970u)) {
        auto targetFn = runtime->lookupFunction(0x1B9970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA068u; }
        if (ctx->pc != 0x1BA068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B9970_0x1b9970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA068u; }
        if (ctx->pc != 0x1BA068u) { return; }
    }
    ctx->pc = 0x1BA068u;
label_1ba068:
    // 0x1ba068: 0x82230004  lb          $v1, 0x4($s1)
    ctx->pc = 0x1ba068u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1ba06c: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1ba06cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ba070: 0x10640037  beq         $v1, $a0, . + 4 + (0x37 << 2)
    ctx->pc = 0x1BA070u;
    {
        const bool branch_taken_0x1ba070 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1BA074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA070u;
            // 0x1ba074: 0x24080001  addiu       $t0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba070) {
            ctx->pc = 0x1BA150u;
            goto label_1ba150;
        }
    }
    ctx->pc = 0x1BA078u;
    // 0x1ba078: 0x1068001a  beq         $v1, $t0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1BA078u;
    {
        const bool branch_taken_0x1ba078 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 8));
        if (branch_taken_0x1ba078) {
            ctx->pc = 0x1BA0E4u;
            goto label_1ba0e4;
        }
    }
    ctx->pc = 0x1BA080u;
    // 0x1ba080: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA080u;
    {
        const bool branch_taken_0x1ba080 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba080) {
            ctx->pc = 0x1BA090u;
            goto label_1ba090;
        }
    }
    ctx->pc = 0x1BA088u;
    // 0x1ba088: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x1BA088u;
    {
        const bool branch_taken_0x1ba088 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA08Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA088u;
            // 0x1ba08c: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba088) {
            ctx->pc = 0x1BA154u;
            goto label_1ba154;
        }
    }
    ctx->pc = 0x1BA090u;
label_1ba090:
    // 0x1ba090: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1ba090u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ba094: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1BA094u;
    {
        const bool branch_taken_0x1ba094 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA098u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA094u;
            // 0x1ba098: 0xa2230004  sb          $v1, 0x4($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 4), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba094) {
            ctx->pc = 0x1BA0BCu;
            goto label_1ba0bc;
        }
    }
    ctx->pc = 0x1BA09Cu;
    // 0x1ba09c: 0x82250002  lb          $a1, 0x2($s1)
    ctx->pc = 0x1ba09cu;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1ba0a0: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1ba0a0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba0a4: 0x27a70038  addiu       $a3, $sp, 0x38
    ctx->pc = 0x1ba0a4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    // 0x1ba0a8: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1ba0a8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba0ac: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1BA0ACu;
    SET_GPR_U32(ctx, 31, 0x1BA0B4u);
    ctx->pc = 0x1BA0B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA0ACu;
            // 0x1ba0b0: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA0B4u; }
        if (ctx->pc != 0x1BA0B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA0B4u; }
        if (ctx->pc != 0x1BA0B4u) { return; }
    }
    ctx->pc = 0x1BA0B4u;
label_1ba0b4:
    // 0x1ba0b4: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1BA0B4u;
    {
        const bool branch_taken_0x1ba0b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA0B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA0B4u;
            // 0x1ba0b8: 0x24030004  addiu       $v1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba0b4) {
            ctx->pc = 0x1BA0E0u;
            goto label_1ba0e0;
        }
    }
    ctx->pc = 0x1BA0BCu;
label_1ba0bc:
    // 0x1ba0bc: 0x82250002  lb          $a1, 0x2($s1)
    ctx->pc = 0x1ba0bcu;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1ba0c0: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1ba0c0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba0c4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1ba0c4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba0c8: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1ba0c8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba0cc: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1BA0CCu;
    SET_GPR_U32(ctx, 31, 0x1BA0D4u);
    ctx->pc = 0x1BA0D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA0CCu;
            // 0x1ba0d0: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA0D4u; }
        if (ctx->pc != 0x1BA0D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA0D4u; }
        if (ctx->pc != 0x1BA0D4u) { return; }
    }
    ctx->pc = 0x1BA0D4u;
label_1ba0d4:
    // 0x1ba0d4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1ba0d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ba0d8: 0xa2230004  sb          $v1, 0x4($s1)
    ctx->pc = 0x1ba0d8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 4), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ba0dc: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1ba0dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_1ba0e0:
    // 0x1ba0e0: 0xa6230008  sh          $v1, 0x8($s1)
    ctx->pc = 0x1ba0e0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 3));
label_1ba0e4:
    // 0x1ba0e4: 0x86230008  lh          $v1, 0x8($s1)
    ctx->pc = 0x1ba0e4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1ba0e8: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1ba0e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1ba0ec: 0xa6230008  sh          $v1, 0x8($s1)
    ctx->pc = 0x1ba0ecu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 3));
    // 0x1ba0f0: 0x31c3c  dsll32      $v1, $v1, 16
    ctx->pc = 0x1ba0f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1ba0f4: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1ba0f4u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1ba0f8: 0x4610015  bgez        $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x1BA0F8u;
    {
        const bool branch_taken_0x1ba0f8 = (GPR_S64(ctx, 3) >= 0);
        if (branch_taken_0x1ba0f8) {
            ctx->pc = 0x1BA150u;
            goto label_1ba150;
        }
    }
    ctx->pc = 0x1BA100u;
    // 0x1ba100: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1ba100u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1ba104: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1ba104u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1ba108: 0xa6220008  sh          $v0, 0x8($s1)
    ctx->pc = 0x1ba108u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x1ba10c: 0x27a40038  addiu       $a0, $sp, 0x38
    ctx->pc = 0x1ba10cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    // 0x1ba110: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1ba110u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1ba114: 0x27a6004c  addiu       $a2, $sp, 0x4C
    ctx->pc = 0x1ba114u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 76));
    // 0x1ba118: 0x24424bf0  addiu       $v0, $v0, 0x4BF0
    ctx->pc = 0x1ba118u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19440));
    // 0x1ba11c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ba11cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ba120: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1ba120u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ba124: 0xc06e52c  jal         func_1B94B0
    ctx->pc = 0x1BA124u;
    SET_GPR_U32(ctx, 31, 0x1BA12Cu);
    ctx->pc = 0x1BA128u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA124u;
            // 0x1ba128: 0x27a70048  addiu       $a3, $sp, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B94B0u;
    if (runtime->hasFunction(0x1B94B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B94B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA12Cu; }
        if (ctx->pc != 0x1BA12Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B94B0_0x1b94b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA12Cu; }
        if (ctx->pc != 0x1BA12Cu) { return; }
    }
    ctx->pc = 0x1BA12Cu;
label_1ba12c:
    // 0x1ba12c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1BA12Cu;
    {
        const bool branch_taken_0x1ba12c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba12c) {
            ctx->pc = 0x1BA150u;
            goto label_1ba150;
        }
    }
    ctx->pc = 0x1BA134u;
    // 0x1ba134: 0x82250002  lb          $a1, 0x2($s1)
    ctx->pc = 0x1ba134u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1ba138: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1ba138u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ba13c: 0x8fa7004c  lw          $a3, 0x4C($sp)
    ctx->pc = 0x1ba13cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x1ba140: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1ba140u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba144: 0x8fa80048  lw          $t0, 0x48($sp)
    ctx->pc = 0x1ba144u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1ba148: 0xc06b2d8  jal         func_1ACB60
    ctx->pc = 0x1BA148u;
    SET_GPR_U32(ctx, 31, 0x1BA150u);
    ctx->pc = 0x1BA14Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA148u;
            // 0x1ba14c: 0x24092000  addiu       $t1, $zero, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACB60u;
    if (runtime->hasFunction(0x1ACB60u)) {
        auto targetFn = runtime->lookupFunction(0x1ACB60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA150u; }
        if (ctx->pc != 0x1BA150u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACB60_0x1acb60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA150u; }
        if (ctx->pc != 0x1BA150u) { return; }
    }
    ctx->pc = 0x1BA150u;
label_1ba150:
    // 0x1ba150: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1ba150u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1ba154:
    // 0x1ba154: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ba154u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ba158: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ba158u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ba15c: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA15Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BA160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA15Cu;
            // 0x1ba160: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA068u: goto label_1ba068;
            case 0x1BA090u: goto label_1ba090;
            case 0x1BA0B4u: goto label_1ba0b4;
            case 0x1BA0BCu: goto label_1ba0bc;
            case 0x1BA0D4u: goto label_1ba0d4;
            case 0x1BA0E0u: goto label_1ba0e0;
            case 0x1BA0E4u: goto label_1ba0e4;
            case 0x1BA12Cu: goto label_1ba12c;
            case 0x1BA150u: goto label_1ba150;
            case 0x1BA154u: goto label_1ba154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA164u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
