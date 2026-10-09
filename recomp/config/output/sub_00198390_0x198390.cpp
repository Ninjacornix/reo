#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00198390
// Address: 0x198390 - 0x198460
void sub_00198390_0x198390(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00198390_0x198390");
#endif

    switch (ctx->pc) {
        case 0x1983b4u: goto label_1983b4;
        case 0x198444u: goto label_198444;
        default: break;
    }

    ctx->pc = 0x198390u;

    // 0x198390: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x198390u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x198394: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x198394u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x198398: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x198398u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19839c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19839cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1983a0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1983a0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1983a4: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1983a4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1983a8: 0x24040030  addiu       $a0, $zero, 0x30
    ctx->pc = 0x1983a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x1983ac: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x1983ACu;
    SET_GPR_U32(ctx, 31, 0x1983B4u);
    ctx->pc = 0x1983B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1983ACu;
            // 0x1983b0: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1983B4u; }
        if (ctx->pc != 0x1983B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1983B4u; }
        if (ctx->pc != 0x1983B4u) { return; }
    }
    ctx->pc = 0x1983B4u;
label_1983b4:
    // 0x1983b4: 0x3403f000  ori         $v1, $zero, 0xF000
    ctx->pc = 0x1983b4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)61440);
    // 0x1983b8: 0x3c041300  lui         $a0, 0x1300
    ctx->pc = 0x1983b8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4864 << 16));
    // 0x1983bc: 0x32c38  dsll        $a1, $v1, 16
    ctx->pc = 0x1983bcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) << 16);
    // 0x1983c0: 0x34a60002  ori         $a2, $a1, 0x2
    ctx->pc = 0x1983c0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)2);
    // 0x1983c4: 0x3c035000  lui         $v1, 0x5000
    ctx->pc = 0x1983c4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)20480 << 16));
    // 0x1983c8: 0x34650002  ori         $a1, $v1, 0x2
    ctx->pc = 0x1983c8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)2);
    // 0x1983cc: 0xfc460000  sd          $a2, 0x0($v0)
    ctx->pc = 0x1983ccu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 6));
    // 0x1983d0: 0xac440008  sw          $a0, 0x8($v0)
    ctx->pc = 0x1983d0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 4));
    // 0x1983d4: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1983d4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1983d8: 0x3203c  dsll32      $a0, $v1, 0
    ctx->pc = 0x1983d8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1983dc: 0xac45000c  sw          $a1, 0xC($v0)
    ctx->pc = 0x1983dcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 5));
    // 0x1983e0: 0x34038001  ori         $v1, $zero, 0x8001
    ctx->pc = 0x1983e0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32769);
    // 0x1983e4: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x1983e4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1983e8: 0xfc440010  sd          $a0, 0x10($v0)
    ctx->pc = 0x1983e8u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 16), GPR_U64(ctx, 4));
    // 0x1983ec: 0x2403000e  addiu       $v1, $zero, 0xE
    ctx->pc = 0x1983ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1983f0: 0x3c040001  lui         $a0, 0x1
    ctx->pc = 0x1983f0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1 << 16));
    // 0x1983f4: 0xfc430018  sd          $v1, 0x18($v0)
    ctx->pc = 0x1983f4u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 24), GPR_U64(ctx, 3));
    // 0x1983f8: 0x2241824  and         $v1, $s1, $a0
    ctx->pc = 0x1983f8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & GPR_U64(ctx, 4));
    // 0x1983fc: 0x14640003  bne         $v1, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1983FCu;
    {
        const bool branch_taken_0x1983fc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x198400u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1983FCu;
            // 0x198400: 0x24030060  addiu       $v1, $zero, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 96));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1983fc) {
            ctx->pc = 0x19840Cu;
            goto label_19840c;
        }
    }
    ctx->pc = 0x198404u;
    // 0x198404: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x198404u;
    {
        const bool branch_taken_0x198404 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198404u;
            // 0x198408: 0xfc400020  sd          $zero, 0x20($v0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198404) {
            ctx->pc = 0x198410u;
            goto label_198410;
        }
    }
    ctx->pc = 0x19840Cu;
label_19840c:
    // 0x19840c: 0xfc430020  sd          $v1, 0x20($v0)
    ctx->pc = 0x19840cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 3));
label_198410:
    // 0x198410: 0x16000004  bnez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x198410u;
    {
        const bool branch_taken_0x198410 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x198414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198410u;
            // 0x198414: 0x24030015  addiu       $v1, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198410) {
            ctx->pc = 0x198424u;
            goto label_198424;
        }
    }
    ctx->pc = 0x198418u;
    // 0x198418: 0x24030014  addiu       $v1, $zero, 0x14
    ctx->pc = 0x198418u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x19841c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x19841Cu;
    {
        const bool branch_taken_0x19841c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198420u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19841Cu;
            // 0x198420: 0xfc430028  sd          $v1, 0x28($v0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19841c) {
            ctx->pc = 0x198428u;
            goto label_198428;
        }
    }
    ctx->pc = 0x198424u;
label_198424:
    // 0x198424: 0xfc430028  sd          $v1, 0x28($v0)
    ctx->pc = 0x198424u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
label_198428:
    // 0x198428: 0x2293c  dsll32      $a1, $v0, 4
    ctx->pc = 0x198428u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
    // 0x19842c: 0x3c07002a  lui         $a3, 0x2A
    ctx->pc = 0x19842cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)42 << 16));
    // 0x198430: 0x5293e  dsrl32      $a1, $a1, 4
    ctx->pc = 0x198430u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 4));
    // 0x198434: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x198434u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x198438: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x198438u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19843c: 0xc0633ec  jal         func_18CFB0
    ctx->pc = 0x19843Cu;
    SET_GPR_U32(ctx, 31, 0x198444u);
    ctx->pc = 0x198440u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19843Cu;
            // 0x198440: 0x24e7f6f0  addiu       $a3, $a3, -0x910 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294964976));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18CFB0u;
    if (runtime->hasFunction(0x18CFB0u)) {
        auto targetFn = runtime->lookupFunction(0x18CFB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x198444u; }
        if (ctx->pc != 0x198444u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x198444u; }
        if (ctx->pc != 0x198444u) { return; }
    }
    ctx->pc = 0x198444u;
label_198444:
    // 0x198444: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x198444u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x198448: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x198448u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19844c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19844cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x198450: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x198450u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x198454: 0x3e00008  jr          $ra
    ctx->pc = 0x198454u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x198458u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198454u;
            // 0x198458: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1983B4u: goto label_1983b4;
            case 0x19840Cu: goto label_19840c;
            case 0x198410u: goto label_198410;
            case 0x198424u: goto label_198424;
            case 0x198428u: goto label_198428;
            case 0x198444u: goto label_198444;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19845Cu;
    // 0x19845c: 0x0  nop
    ctx->pc = 0x19845cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
