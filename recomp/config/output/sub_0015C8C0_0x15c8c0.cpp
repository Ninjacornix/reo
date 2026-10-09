#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015C8C0
// Address: 0x15c8c0 - 0x15ca20
void sub_0015C8C0_0x15c8c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015C8C0_0x15c8c0");
#endif

    switch (ctx->pc) {
        case 0x15c958u: goto label_15c958;
        default: break;
    }

    ctx->pc = 0x15c8c0u;

label_15c8c0:
    // 0x15c8c0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x15c8c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15c8c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15c8c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15c8c8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15c8c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c8cc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15c8ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15c8d0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15c8d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15c8d4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x15c8d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x15c8d8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x15c8d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x15c8dc: 0x8e0500d4  lw          $a1, 0xD4($s0)
    ctx->pc = 0x15c8dcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 212)));
    // 0x15c8e0: 0x54a0000b  bnel        $a1, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x15C8E0u;
    {
        const bool branch_taken_0x15c8e0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x15c8e0) {
            ctx->pc = 0x15C8E4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15C8E0u;
            // 0x15c8e4: 0x8e03001c  lw          $v1, 0x1C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15C910u;
            goto label_15c910;
        }
    }
    ctx->pc = 0x15C8E8u;
    // 0x15c8e8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15c8e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15c8ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15c8ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15c8f0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15c8f0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15c8f4: 0x2484e810  addiu       $a0, $a0, -0x17F0
    ctx->pc = 0x15c8f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961168));
    // 0x15c8f8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15c8f8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15c8fc: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x15c8fcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15c900: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15c900u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15c904: 0x8058dd4  j           func_163750
    ctx->pc = 0x15C904u;
    ctx->pc = 0x15C908u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C904u;
            // 0x15c908: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15C90Cu;
    // 0x15c90c: 0x0  nop
    ctx->pc = 0x15c90cu;
    // NOP
label_15c910:
    // 0x15c910: 0x8cb30008  lw          $s3, 0x8($a1)
    ctx->pc = 0x15c910u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x15c914: 0x24720004  addiu       $s2, $v1, 0x4
    ctx->pc = 0x15c914u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x15c918: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x15c918u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x15c91c: 0x2531818  mult        $v1, $s2, $s3
    ctx->pc = 0x15c91cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 19); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x15c920: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x15c920u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x15c924: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x15C924u;
    {
        const bool branch_taken_0x15c924 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C928u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C924u;
            // 0x15c928: 0x8cb10000  lw          $s1, 0x0($a1) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c924) {
            ctx->pc = 0x15C950u;
            goto label_15c950;
        }
    }
    ctx->pc = 0x15C92Cu;
    // 0x15c92c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15c92cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15c930: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15c930u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15c934: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15c934u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15c938: 0x2484e848  addiu       $a0, $a0, -0x17B8
    ctx->pc = 0x15c938u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961224));
    // 0x15c93c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15c93cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15c940: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x15c940u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15c944: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15c944u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15c948: 0x8058dd4  j           func_163750
    ctx->pc = 0x15C948u;
    ctx->pc = 0x15C94Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C948u;
            // 0x15c94c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15C950u;
label_15c950:
    // 0x15c950: 0xc057a4c  jal         func_15E930
    ctx->pc = 0x15C950u;
    SET_GPR_U32(ctx, 31, 0x15C958u);
    ctx->pc = 0x15E930u;
    if (runtime->hasFunction(0x15E930u)) {
        auto targetFn = runtime->lookupFunction(0x15E930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C958u; }
        if (ctx->pc != 0x15C958u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E930_0x15e930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15C958u; }
        if (ctx->pc != 0x15C958u) { return; }
    }
    ctx->pc = 0x15C958u;
label_15c958:
    // 0x15c958: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x15c958u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15c95c: 0x5443000c  bnel        $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x15C95Cu;
    {
        const bool branch_taken_0x15c95c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x15c95c) {
            ctx->pc = 0x15C960u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15C95Cu;
            // 0x15c960: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15C990u;
            goto label_15c990;
        }
    }
    ctx->pc = 0x15C964u;
    // 0x15c964: 0x8e040040  lw          $a0, 0x40($s0)
    ctx->pc = 0x15c964u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x15c968: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x15c968u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c96c: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x15c96cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c970: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15c970u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15c974: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x15c974u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c978: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x15c978u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15c97c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15c97cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15c980: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15c980u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15c984: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15c984u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15c988: 0x805b03a  j           func_16C0E8
    ctx->pc = 0x15C988u;
    ctx->pc = 0x15C98Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C988u;
            // 0x15c98c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16C0E8u;
    if (runtime->hasFunction(0x16C0E8u)) {
        auto targetFn = runtime->lookupFunction(0x16C0E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0016C0E8_0x16c0e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15C990u;
label_15c990:
    // 0x15c990: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15c990u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15c994: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15c994u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15c998: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x15c998u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15c99c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15c99cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15c9a0: 0x3e00008  jr          $ra
    ctx->pc = 0x15C9A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15C9A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C9A0u;
            // 0x15c9a4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15C8C0u: goto label_15c8c0;
            case 0x15C910u: goto label_15c910;
            case 0x15C950u: goto label_15c950;
            case 0x15C958u: goto label_15c958;
            case 0x15C990u: goto label_15c990;
            case 0x15C9D8u: goto label_15c9d8;
            case 0x15CA08u: goto label_15ca08;
            case 0x15CA14u: goto label_15ca14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15C9A8u;
    // 0x15c9a8: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x15c9a8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c9ac: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15c9acu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15c9b0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15c9b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15c9b4: 0x250300c8  addiu       $v1, $t0, 0xC8
    ctx->pc = 0x15c9b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), 200));
    // 0x15c9b8: 0x14a00007  bnez        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x15C9B8u;
    {
        const bool branch_taken_0x15c9b8 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x15C9BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C9B8u;
            // 0x15c9bc: 0x250200bc  addiu       $v0, $t0, 0xBC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 188));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c9b8) {
            ctx->pc = 0x15C9D8u;
            goto label_15c9d8;
        }
    }
    ctx->pc = 0x15C9C0u;
    // 0x15c9c0: 0xac600008  sw          $zero, 0x8($v1)
    ctx->pc = 0x15c9c0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 0));
    // 0x15c9c4: 0xad0200d4  sw          $v0, 0xD4($t0)
    ctx->pc = 0x15c9c4u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 212), GPR_U32(ctx, 2));
    // 0x15c9c8: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x15c9c8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x15c9cc: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x15C9CCu;
    {
        const bool branch_taken_0x15c9cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C9D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C9CCu;
            // 0x15c9d0: 0xac600004  sw          $zero, 0x4($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c9cc) {
            ctx->pc = 0x15CA14u;
            goto label_15ca14;
        }
    }
    ctx->pc = 0x15C9D4u;
    // 0x15c9d4: 0x0  nop
    ctx->pc = 0x15c9d4u;
    // NOP
label_15c9d8:
    // 0x15c9d8: 0x8d02001c  lw          $v0, 0x1C($t0)
    ctx->pc = 0x15c9d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 28)));
    // 0x15c9dc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x15c9dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x15c9e0: 0x471018  mult        $v0, $v0, $a3
    ctx->pc = 0x15c9e0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x15c9e4: 0xc2102a  slt         $v0, $a2, $v0
    ctx->pc = 0x15c9e4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x15c9e8: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x15C9E8u;
    {
        const bool branch_taken_0x15c9e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x15c9e8) {
            ctx->pc = 0x15C9ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15C9E8u;
            // 0x15c9ec: 0xac650000  sw          $a1, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15CA08u;
            goto label_15ca08;
        }
    }
    ctx->pc = 0x15C9F0u;
    // 0x15c9f0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15c9f0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15c9f4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15c9f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15c9f8: 0x2484e888  addiu       $a0, $a0, -0x1778
    ctx->pc = 0x15c9f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961288));
    // 0x15c9fc: 0x8058dd4  j           func_163750
    ctx->pc = 0x15C9FCu;
    ctx->pc = 0x15CA00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C9FCu;
            // 0x15ca00: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15CA04u;
    // 0x15ca04: 0x0  nop
    ctx->pc = 0x15ca04u;
    // NOP
label_15ca08:
    // 0x15ca08: 0xac660004  sw          $a2, 0x4($v1)
    ctx->pc = 0x15ca08u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 6));
    // 0x15ca0c: 0xac670008  sw          $a3, 0x8($v1)
    ctx->pc = 0x15ca0cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 7));
    // 0x15ca10: 0xad0300d4  sw          $v1, 0xD4($t0)
    ctx->pc = 0x15ca10u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 212), GPR_U32(ctx, 3));
label_15ca14:
    // 0x15ca14: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ca14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ca18: 0x8057230  j           func_15C8C0
    ctx->pc = 0x15CA18u;
    ctx->pc = 0x15CA1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CA18u;
            // 0x15ca1c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15C8C0u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_15c8c0;
    ctx->pc = 0x15CA20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
