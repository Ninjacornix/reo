#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A7900
// Address: 0x1a7900 - 0x1a7bb0
void sub_001A7900_0x1a7900(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A7900_0x1a7900");
#endif

    switch (ctx->pc) {
        case 0x1a791cu: goto label_1a791c;
        case 0x1a7944u: goto label_1a7944;
        case 0x1a798cu: goto label_1a798c;
        case 0x1a79acu: goto label_1a79ac;
        case 0x1a79d0u: goto label_1a79d0;
        case 0x1a7a6cu: goto label_1a7a6c;
        case 0x1a7ac0u: goto label_1a7ac0;
        case 0x1a7b50u: goto label_1a7b50;
        default: break;
    }

    ctx->pc = 0x1a7900u;

    // 0x1a7900: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a7900u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a7904: 0x2c811000  sltiu       $at, $a0, 0x1000
    ctx->pc = 0x1a7904u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)4096) ? 1 : 0);
    // 0x1a7908: 0x14200006  bnez        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A7908u;
    {
        const bool branch_taken_0x1a7908 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A790Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7908u;
            // 0x1a790c: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7908) {
            ctx->pc = 0x1A7924u;
            goto label_1a7924;
        }
    }
    ctx->pc = 0x1A7910u;
    // 0x1a7910: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a7910u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a7914: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A7914u;
    SET_GPR_U32(ctx, 31, 0x1A791Cu);
    ctx->pc = 0x1A7918u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7914u;
            // 0x1a7918: 0x248421b0  addiu       $a0, $a0, 0x21B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8624));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A791Cu; }
        if (ctx->pc != 0x1A791Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A791Cu; }
        if (ctx->pc != 0x1A791Cu) { return; }
    }
    ctx->pc = 0x1A791Cu;
label_1a791c:
    // 0x1a791c: 0x10000054  b           . + 4 + (0x54 << 2)
    ctx->pc = 0x1A791Cu;
    {
        const bool branch_taken_0x1a791c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7920u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A791Cu;
            // 0x1a7920: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a791c) {
            ctx->pc = 0x1A7A70u;
            goto label_1a7a70;
        }
    }
    ctx->pc = 0x1A7924u;
label_1a7924:
    // 0x1a7924: 0xa71025  or          $v0, $a1, $a3
    ctx->pc = 0x1a7924u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) | GPR_U64(ctx, 7));
    // 0x1a7928: 0x1221025  or          $v0, $t1, $v0
    ctx->pc = 0x1a7928u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x1a792c: 0x3042000f  andi        $v0, $v0, 0xF
    ctx->pc = 0x1a792cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x1a7930: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A7930u;
    {
        const bool branch_taken_0x1a7930 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7930u;
            // 0x1a7934: 0x3c01001f  lui         $at, 0x1F (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)31 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7930) {
            ctx->pc = 0x1A794Cu;
            goto label_1a794c;
        }
    }
    ctx->pc = 0x1A7938u;
    // 0x1a7938: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a7938u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a793c: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A793Cu;
    SET_GPR_U32(ctx, 31, 0x1A7944u);
    ctx->pc = 0x1A7940u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A793Cu;
            // 0x1a7940: 0x248421e0  addiu       $a0, $a0, 0x21E0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8672));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7944u; }
        if (ctx->pc != 0x1A7944u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7944u; }
        if (ctx->pc != 0x1A7944u) { return; }
    }
    ctx->pc = 0x1A7944u;
label_1a7944:
    // 0x1a7944: 0x1000004a  b           . + 4 + (0x4A << 2)
    ctx->pc = 0x1A7944u;
    {
        const bool branch_taken_0x1a7944 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7948u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7944u;
            // 0x1a7948: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7944) {
            ctx->pc = 0x1A7A70u;
            goto label_1a7a70;
        }
    }
    ctx->pc = 0x1A794Cu;
label_1a794c:
    // 0x1a794c: 0x3421fff1  ori         $at, $at, 0xFFF1
    ctx->pc = 0x1a794cu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)65521);
    // 0x1a7950: 0xc1082a  slt         $at, $a2, $at
    ctx->pc = 0x1a7950u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 1)) ? 1 : 0);
    // 0x1a7954: 0x1020000a  beqz        $at, . + 4 + (0xA << 2)
    ctx->pc = 0x1A7954u;
    {
        const bool branch_taken_0x1a7954 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a7954) {
            ctx->pc = 0x1A7980u;
            goto label_1a7980;
        }
    }
    ctx->pc = 0x1A795Cu;
    // 0x1a795c: 0x3c01001f  lui         $at, 0x1F
    ctx->pc = 0x1a795cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)31 << 16));
    // 0x1a7960: 0x3421fff1  ori         $at, $at, 0xFFF1
    ctx->pc = 0x1a7960u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)65521);
    // 0x1a7964: 0x101082a  slt         $at, $t0, $at
    ctx->pc = 0x1a7964u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 1)) ? 1 : 0);
    // 0x1a7968: 0x10200005  beqz        $at, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A7968u;
    {
        const bool branch_taken_0x1a7968 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A796Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7968u;
            // 0x1a796c: 0x3c01001f  lui         $at, 0x1F (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)31 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7968) {
            ctx->pc = 0x1A7980u;
            goto label_1a7980;
        }
    }
    ctx->pc = 0x1A7970u;
    // 0x1a7970: 0x3421fff1  ori         $at, $at, 0xFFF1
    ctx->pc = 0x1a7970u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)65521);
    // 0x1a7974: 0x141082a  slt         $at, $t2, $at
    ctx->pc = 0x1a7974u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 10) < (int64_t)GPR_S64(ctx, 1)) ? 1 : 0);
    // 0x1a7978: 0x14200006  bnez        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A7978u;
    {
        const bool branch_taken_0x1a7978 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a7978) {
            ctx->pc = 0x1A7994u;
            goto label_1a7994;
        }
    }
    ctx->pc = 0x1A7980u;
label_1a7980:
    // 0x1a7980: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a7980u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a7984: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A7984u;
    SET_GPR_U32(ctx, 31, 0x1A798Cu);
    ctx->pc = 0x1A7988u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7984u;
            // 0x1a7988: 0x24842230  addiu       $a0, $a0, 0x2230 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8752));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A798Cu; }
        if (ctx->pc != 0x1A798Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A798Cu; }
        if (ctx->pc != 0x1A798Cu) { return; }
    }
    ctx->pc = 0x1A798Cu;
label_1a798c:
    // 0x1a798c: 0x10000038  b           . + 4 + (0x38 << 2)
    ctx->pc = 0x1A798Cu;
    {
        const bool branch_taken_0x1a798c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7990u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A798Cu;
            // 0x1a7990: 0x2402fffc  addiu       $v0, $zero, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a798c) {
            ctx->pc = 0x1A7A70u;
            goto label_1a7a70;
        }
    }
    ctx->pc = 0x1A7994u;
label_1a7994:
    // 0x1a7994: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7994u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7998: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a7998u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a799c: 0x8c2b0a68  lw          $t3, 0xA68($at)
    ctx->pc = 0x1a799cu;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a79a0: 0x240c0004  addiu       $t4, $zero, 0x4
    ctx->pc = 0x1a79a0u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1a79a4: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1A79A4u;
    {
        const bool branch_taken_0x1a79a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A79A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A79A4u;
            // 0x1a79a8: 0x24630a80  addiu       $v1, $v1, 0xA80 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2688));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a79a4) {
            ctx->pc = 0x1A79F0u;
            goto label_1a79f0;
        }
    }
    ctx->pc = 0x1A79ACu;
label_1a79ac:
    // 0x1a79ac: 0x4b1021  addu        $v0, $v0, $t3
    ctx->pc = 0x1a79acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 11)));
    // 0x1a79b0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1a79b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1a79b4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a79b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a79b8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1a79b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a79bc: 0x4400006  bltz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A79BCu;
    {
        const bool branch_taken_0x1a79bc = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1A79C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A79BCu;
            // 0x1a79c0: 0x25620001  addiu       $v0, $t3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 11), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a79bc) {
            ctx->pc = 0x1A79D8u;
            goto label_1a79d8;
        }
    }
    ctx->pc = 0x1A79C4u;
    // 0x1a79c4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a79c4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a79c8: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A79C8u;
    SET_GPR_U32(ctx, 31, 0x1A79D0u);
    ctx->pc = 0x1A79CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A79C8u;
            // 0x1a79cc: 0x24842260  addiu       $a0, $a0, 0x2260 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8800));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A79D0u; }
        if (ctx->pc != 0x1A79D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A79D0u; }
        if (ctx->pc != 0x1A79D0u) { return; }
    }
    ctx->pc = 0x1A79D0u;
label_1a79d0:
    // 0x1a79d0: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x1A79D0u;
    {
        const bool branch_taken_0x1a79d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A79D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A79D0u;
            // 0x1a79d4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a79d0) {
            ctx->pc = 0x1A7A70u;
            goto label_1a7a70;
        }
    }
    ctx->pc = 0x1A79D8u;
label_1a79d8:
    // 0x1a79d8: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A79D8u;
    {
        const bool branch_taken_0x1a79d8 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1A79DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A79D8u;
            // 0x1a79dc: 0x304b001f  andi        $t3, $v0, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 11, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)31);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a79d8) {
            ctx->pc = 0x1A79ECu;
            goto label_1a79ec;
        }
    }
    ctx->pc = 0x1A79E0u;
    // 0x1a79e0: 0x11600002  beqz        $t3, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A79E0u;
    {
        const bool branch_taken_0x1a79e0 = (GPR_U64(ctx, 11) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a79e0) {
            ctx->pc = 0x1A79ECu;
            goto label_1a79ec;
        }
    }
    ctx->pc = 0x1A79E8u;
    // 0x1a79e8: 0x256bffe0  addiu       $t3, $t3, -0x20
    ctx->pc = 0x1a79e8u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 4294967264));
label_1a79ec:
    // 0x1a79ec: 0x258cffff  addiu       $t4, $t4, -0x1
    ctx->pc = 0x1a79ecu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 4294967295));
label_1a79f0:
    // 0x1a79f0: 0x1d80ffee  bgtz        $t4, . + 4 + (-0x12 << 2)
    ctx->pc = 0x1A79F0u;
    {
        const bool branch_taken_0x1a79f0 = (GPR_S64(ctx, 12) > 0);
        ctx->pc = 0x1A79F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A79F0u;
            // 0x1a79f4: 0xb1040  sll         $v0, $t3, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 11), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a79f0) {
            ctx->pc = 0x1A79ACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a79ac;
        }
    }
    ctx->pc = 0x1A79F8u;
    // 0x1a79f8: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a79f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a79fc: 0x41200  sll         $v0, $a0, 8
    ctx->pc = 0x1a79fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x1a7a00: 0x8c2b0a68  lw          $t3, 0xA68($at)
    ctx->pc = 0x1a7a00u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a7a04: 0x21a3c  dsll32      $v1, $v0, 8
    ctx->pc = 0x1a7a04u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 8));
    // 0x1a7a08: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a7a08u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a7a0c: 0x31a3e  dsrl32      $v1, $v1, 8
    ctx->pc = 0x1a7a0cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 8));
    // 0x1a7a10: 0x3c024d00  lui         $v0, 0x4D00
    ctx->pc = 0x1a7a10u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)19712 << 16));
    // 0x1a7a14: 0x24840a80  addiu       $a0, $a0, 0xA80
    ctx->pc = 0x1a7a14u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2688));
    // 0x1a7a18: 0x626025  or          $t4, $v1, $v0
    ctx->pc = 0x1a7a18u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1a7a1c: 0xb1040  sll         $v0, $t3, 1
    ctx->pc = 0x1a7a1cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 11), 1));
    // 0x1a7a20: 0x25630001  addiu       $v1, $t3, 0x1
    ctx->pc = 0x1a7a20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 11), 1));
    // 0x1a7a24: 0x4b5821  addu        $t3, $v0, $t3
    ctx->pc = 0x1a7a24u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 11)));
    // 0x1a7a28: 0xb5880  sll         $t3, $t3, 2
    ctx->pc = 0x1a7a28u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 2));
    // 0x1a7a2c: 0x3062001f  andi        $v0, $v1, 0x1F
    ctx->pc = 0x1a7a2cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)31);
    // 0x1a7a30: 0x8b2021  addu        $a0, $a0, $t3
    ctx->pc = 0x1a7a30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
    // 0x1a7a34: 0x4610004  bgez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A7A34u;
    {
        const bool branch_taken_0x1a7a34 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1A7A38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7A34u;
            // 0x1a7a38: 0xac8c0000  sw          $t4, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7a34) {
            ctx->pc = 0x1A7A48u;
            goto label_1a7a48;
        }
    }
    ctx->pc = 0x1A7A3Cu;
    // 0x1a7a3c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A7A3Cu;
    {
        const bool branch_taken_0x1a7a3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7A40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7A3Cu;
            // 0x1a7a40: 0xa0202d  daddu       $a0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7a3c) {
            ctx->pc = 0x1A7A4Cu;
            goto label_1a7a4c;
        }
    }
    ctx->pc = 0x1A7A44u;
    // 0x1a7a44: 0x2442ffe0  addiu       $v0, $v0, -0x20
    ctx->pc = 0x1a7a44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967264));
label_1a7a48:
    // 0x1a7a48: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1a7a48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_1a7a4c:
    // 0x1a7a4c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7a4cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7a50: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x1a7a50u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a7a54: 0xac220a68  sw          $v0, 0xA68($at)
    ctx->pc = 0x1a7a54u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2664), GPR_U32(ctx, 2));
    // 0x1a7a58: 0xe0302d  daddu       $a2, $a3, $zero
    ctx->pc = 0x1a7a58u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a7a5c: 0x100382d  daddu       $a3, $t0, $zero
    ctx->pc = 0x1a7a5cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a7a60: 0x120402d  daddu       $t0, $t1, $zero
    ctx->pc = 0x1a7a60u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a7a64: 0xc069df4  jal         func_1A77D0
    ctx->pc = 0x1A7A64u;
    SET_GPR_U32(ctx, 31, 0x1A7A6Cu);
    ctx->pc = 0x1A7A68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7A64u;
            // 0x1a7a68: 0x140482d  daddu       $t1, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A77D0u;
    if (runtime->hasFunction(0x1A77D0u)) {
        auto targetFn = runtime->lookupFunction(0x1A77D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7A6Cu; }
        if (ctx->pc != 0x1A7A6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A77D0_0x1a77d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7A6Cu; }
        if (ctx->pc != 0x1A7A6Cu) { return; }
    }
    ctx->pc = 0x1A7A6Cu;
label_1a7a6c:
    // 0x1a7a6c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a7a6cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a7a70:
    // 0x1a7a70: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a7a70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a7a74: 0x3e00008  jr          $ra
    ctx->pc = 0x1A7A74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A7A78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7A74u;
            // 0x1a7a78: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A791Cu: goto label_1a791c;
            case 0x1A7924u: goto label_1a7924;
            case 0x1A7944u: goto label_1a7944;
            case 0x1A794Cu: goto label_1a794c;
            case 0x1A7980u: goto label_1a7980;
            case 0x1A798Cu: goto label_1a798c;
            case 0x1A7994u: goto label_1a7994;
            case 0x1A79ACu: goto label_1a79ac;
            case 0x1A79D0u: goto label_1a79d0;
            case 0x1A79D8u: goto label_1a79d8;
            case 0x1A79ECu: goto label_1a79ec;
            case 0x1A79F0u: goto label_1a79f0;
            case 0x1A7A48u: goto label_1a7a48;
            case 0x1A7A4Cu: goto label_1a7a4c;
            case 0x1A7A6Cu: goto label_1a7a6c;
            case 0x1A7A70u: goto label_1a7a70;
            case 0x1A7AC0u: goto label_1a7ac0;
            case 0x1A7AC8u: goto label_1a7ac8;
            case 0x1A7AECu: goto label_1a7aec;
            case 0x1A7AF8u: goto label_1a7af8;
            case 0x1A7B50u: goto label_1a7b50;
            case 0x1A7B58u: goto label_1a7b58;
            case 0x1A7B90u: goto label_1a7b90;
            case 0x1A7B9Cu: goto label_1a7b9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A7A7Cu;
    // 0x1a7a7c: 0x0  nop
    ctx->pc = 0x1a7a7cu;
    // NOP
    // 0x1a7a80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a7a80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a7a84: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a7a84u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a7a88: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a7a88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a7a8c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7a8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7a90: 0x8c240a68  lw          $a0, 0xA68($at)
    ctx->pc = 0x1a7a90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a7a94: 0x24420a80  addiu       $v0, $v0, 0xA80
    ctx->pc = 0x1a7a94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2688));
    // 0x1a7a98: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1a7a98u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1a7a9c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1a7a9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1a7aa0: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1a7aa0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a7aa4: 0x431821  addu        $v1, $v0, $v1
    ctx->pc = 0x1a7aa4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a7aa8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1a7aa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a7aac: 0x4400006  bltz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A7AACu;
    {
        const bool branch_taken_0x1a7aac = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1A7AB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7AACu;
            // 0x1a7ab0: 0x3c024000  lui         $v0, 0x4000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16384 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7aac) {
            ctx->pc = 0x1A7AC8u;
            goto label_1a7ac8;
        }
    }
    ctx->pc = 0x1A7AB4u;
    // 0x1a7ab4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a7ab4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a7ab8: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A7AB8u;
    SET_GPR_U32(ctx, 31, 0x1A7AC0u);
    ctx->pc = 0x1A7ABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7AB8u;
            // 0x1a7abc: 0x248422c0  addiu       $a0, $a0, 0x22C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8896));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7AC0u; }
        if (ctx->pc != 0x1A7AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7AC0u; }
        if (ctx->pc != 0x1A7AC0u) { return; }
    }
    ctx->pc = 0x1A7AC0u;
label_1a7ac0:
    // 0x1a7ac0: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1A7AC0u;
    {
        const bool branch_taken_0x1a7ac0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7AC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7AC0u;
            // 0x1a7ac4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7ac0) {
            ctx->pc = 0x1A7AF8u;
            goto label_1a7af8;
        }
    }
    ctx->pc = 0x1A7AC8u;
label_1a7ac8:
    // 0x1a7ac8: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7ac8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7acc: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1a7accu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1a7ad0: 0x8c220a68  lw          $v0, 0xA68($at)
    ctx->pc = 0x1a7ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a7ad4: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1a7ad4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a7ad8: 0x4610004  bgez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A7AD8u;
    {
        const bool branch_taken_0x1a7ad8 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1A7ADCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7AD8u;
            // 0x1a7adc: 0x3062001f  andi        $v0, $v1, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)31);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7ad8) {
            ctx->pc = 0x1A7AECu;
            goto label_1a7aec;
        }
    }
    ctx->pc = 0x1A7AE0u;
    // 0x1a7ae0: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A7AE0u;
    {
        const bool branch_taken_0x1a7ae0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a7ae0) {
            ctx->pc = 0x1A7AECu;
            goto label_1a7aec;
        }
    }
    ctx->pc = 0x1A7AE8u;
    // 0x1a7ae8: 0x2442ffe0  addiu       $v0, $v0, -0x20
    ctx->pc = 0x1a7ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967264));
label_1a7aec:
    // 0x1a7aec: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7aecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7af0: 0xac220a68  sw          $v0, 0xA68($at)
    ctx->pc = 0x1a7af0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2664), GPR_U32(ctx, 2));
    // 0x1a7af4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a7af4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a7af8:
    // 0x1a7af8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a7af8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a7afc: 0x3e00008  jr          $ra
    ctx->pc = 0x1A7AFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A7B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7AFCu;
            // 0x1a7b00: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A791Cu: goto label_1a791c;
            case 0x1A7924u: goto label_1a7924;
            case 0x1A7944u: goto label_1a7944;
            case 0x1A794Cu: goto label_1a794c;
            case 0x1A7980u: goto label_1a7980;
            case 0x1A798Cu: goto label_1a798c;
            case 0x1A7994u: goto label_1a7994;
            case 0x1A79ACu: goto label_1a79ac;
            case 0x1A79D0u: goto label_1a79d0;
            case 0x1A79D8u: goto label_1a79d8;
            case 0x1A79ECu: goto label_1a79ec;
            case 0x1A79F0u: goto label_1a79f0;
            case 0x1A7A48u: goto label_1a7a48;
            case 0x1A7A4Cu: goto label_1a7a4c;
            case 0x1A7A6Cu: goto label_1a7a6c;
            case 0x1A7A70u: goto label_1a7a70;
            case 0x1A7AC0u: goto label_1a7ac0;
            case 0x1A7AC8u: goto label_1a7ac8;
            case 0x1A7AECu: goto label_1a7aec;
            case 0x1A7AF8u: goto label_1a7af8;
            case 0x1A7B50u: goto label_1a7b50;
            case 0x1A7B58u: goto label_1a7b58;
            case 0x1A7B90u: goto label_1a7b90;
            case 0x1A7B9Cu: goto label_1a7b9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A7B04u;
    // 0x1a7b04: 0x0  nop
    ctx->pc = 0x1a7b04u;
    // NOP
    // 0x1a7b08: 0x0  nop
    ctx->pc = 0x1a7b08u;
    // NOP
    // 0x1a7b0c: 0x0  nop
    ctx->pc = 0x1a7b0cu;
    // NOP
    // 0x1a7b10: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a7b10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a7b14: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a7b14u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a7b18: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a7b18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a7b1c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7b1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7b20: 0x8c250a68  lw          $a1, 0xA68($at)
    ctx->pc = 0x1a7b20u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a7b24: 0x24420a80  addiu       $v0, $v0, 0xA80
    ctx->pc = 0x1a7b24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2688));
    // 0x1a7b28: 0x51840  sll         $v1, $a1, 1
    ctx->pc = 0x1a7b28u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1a7b2c: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1a7b2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1a7b30: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1a7b30u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a7b34: 0x432821  addu        $a1, $v0, $v1
    ctx->pc = 0x1a7b34u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a7b38: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x1a7b38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1a7b3c: 0x4400006  bltz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A7B3Cu;
    {
        const bool branch_taken_0x1a7b3c = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1A7B40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7B3Cu;
            // 0x1a7b40: 0x308300ff  andi        $v1, $a0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7b3c) {
            ctx->pc = 0x1A7B58u;
            goto label_1a7b58;
        }
    }
    ctx->pc = 0x1A7B44u;
    // 0x1a7b44: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a7b44u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a7b48: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A7B48u;
    SET_GPR_U32(ctx, 31, 0x1A7B50u);
    ctx->pc = 0x1A7B4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7B48u;
            // 0x1a7b4c: 0x24842290  addiu       $a0, $a0, 0x2290 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8848));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7B50u; }
        if (ctx->pc != 0x1A7B50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7B50u; }
        if (ctx->pc != 0x1A7B50u) { return; }
    }
    ctx->pc = 0x1A7B50u;
label_1a7b50:
    // 0x1a7b50: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1A7B50u;
    {
        const bool branch_taken_0x1a7b50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7B54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7B50u;
            // 0x1a7b54: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7b50) {
            ctx->pc = 0x1A7B9Cu;
            goto label_1a7b9c;
        }
    }
    ctx->pc = 0x1A7B58u;
label_1a7b58:
    // 0x1a7b58: 0x3c024a00  lui         $v0, 0x4A00
    ctx->pc = 0x1a7b58u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)18944 << 16));
    // 0x1a7b5c: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x1a7b5cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x1a7b60: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7b60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7b64: 0x31a3c  dsll32      $v1, $v1, 8
    ctx->pc = 0x1a7b64u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 8));
    // 0x1a7b68: 0x31a3e  dsrl32      $v1, $v1, 8
    ctx->pc = 0x1a7b68u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 8));
    // 0x1a7b6c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1a7b6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1a7b70: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1a7b70u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1a7b74: 0x8c220a68  lw          $v0, 0xA68($at)
    ctx->pc = 0x1a7b74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a7b78: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1a7b78u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a7b7c: 0x4610004  bgez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A7B7Cu;
    {
        const bool branch_taken_0x1a7b7c = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1A7B80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7B7Cu;
            // 0x1a7b80: 0x3062001f  andi        $v0, $v1, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)31);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7b7c) {
            ctx->pc = 0x1A7B90u;
            goto label_1a7b90;
        }
    }
    ctx->pc = 0x1A7B84u;
    // 0x1a7b84: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A7B84u;
    {
        const bool branch_taken_0x1a7b84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a7b84) {
            ctx->pc = 0x1A7B90u;
            goto label_1a7b90;
        }
    }
    ctx->pc = 0x1A7B8Cu;
    // 0x1a7b8c: 0x2442ffe0  addiu       $v0, $v0, -0x20
    ctx->pc = 0x1a7b8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967264));
label_1a7b90:
    // 0x1a7b90: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7b90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7b94: 0xac220a68  sw          $v0, 0xA68($at)
    ctx->pc = 0x1a7b94u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2664), GPR_U32(ctx, 2));
    // 0x1a7b98: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a7b98u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a7b9c:
    // 0x1a7b9c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a7b9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a7ba0: 0x3e00008  jr          $ra
    ctx->pc = 0x1A7BA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A7BA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7BA0u;
            // 0x1a7ba4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A791Cu: goto label_1a791c;
            case 0x1A7924u: goto label_1a7924;
            case 0x1A7944u: goto label_1a7944;
            case 0x1A794Cu: goto label_1a794c;
            case 0x1A7980u: goto label_1a7980;
            case 0x1A798Cu: goto label_1a798c;
            case 0x1A7994u: goto label_1a7994;
            case 0x1A79ACu: goto label_1a79ac;
            case 0x1A79D0u: goto label_1a79d0;
            case 0x1A79D8u: goto label_1a79d8;
            case 0x1A79ECu: goto label_1a79ec;
            case 0x1A79F0u: goto label_1a79f0;
            case 0x1A7A48u: goto label_1a7a48;
            case 0x1A7A4Cu: goto label_1a7a4c;
            case 0x1A7A6Cu: goto label_1a7a6c;
            case 0x1A7A70u: goto label_1a7a70;
            case 0x1A7AC0u: goto label_1a7ac0;
            case 0x1A7AC8u: goto label_1a7ac8;
            case 0x1A7AECu: goto label_1a7aec;
            case 0x1A7AF8u: goto label_1a7af8;
            case 0x1A7B50u: goto label_1a7b50;
            case 0x1A7B58u: goto label_1a7b58;
            case 0x1A7B90u: goto label_1a7b90;
            case 0x1A7B9Cu: goto label_1a7b9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A7BA8u;
    // 0x1a7ba8: 0x0  nop
    ctx->pc = 0x1a7ba8u;
    // NOP
    // 0x1a7bac: 0x0  nop
    ctx->pc = 0x1a7bacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
