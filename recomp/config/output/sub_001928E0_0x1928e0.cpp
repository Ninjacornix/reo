#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001928E0
// Address: 0x1928e0 - 0x192978
void sub_001928E0_0x1928e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001928E0_0x1928e0");
#endif

    switch (ctx->pc) {
        case 0x192900u: goto label_192900;
        case 0x192918u: goto label_192918;
        case 0x192940u: goto label_192940;
        default: break;
    }

    ctx->pc = 0x1928e0u;

    // 0x1928e0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1928e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1928e4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1928e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1928e8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1928e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1928ec: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1928ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1928f0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1928f0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1928f4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1928f4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1928f8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1928f8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1928fc: 0x220802d  daddu       $s0, $s1, $zero
    ctx->pc = 0x1928fcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_192900:
    // 0x192900: 0x862200c4  lh          $v0, 0xC4($s1)
    ctx->pc = 0x192900u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 196)));
    // 0x192904: 0x26250080  addiu       $a1, $s1, 0x80
    ctx->pc = 0x192904u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 128));
    // 0x192908: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x192908u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19290c: 0x21180  sll         $v0, $v0, 6
    ctx->pc = 0x19290cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x192910: 0xc0644a0  jal         func_191280
    ctx->pc = 0x192910u;
    SET_GPR_U32(ctx, 31, 0x192918u);
    ctx->pc = 0x192914u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192910u;
            // 0x192914: 0x2422021  addu        $a0, $s2, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192918u; }
        if (ctx->pc != 0x192918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192918u; }
        if (ctx->pc != 0x192918u) { return; }
    }
    ctx->pc = 0x192918u;
label_192918:
    // 0x192918: 0x8e2300d0  lw          $v1, 0xD0($s1)
    ctx->pc = 0x192918u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 208)));
    // 0x19291c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x19291Cu;
    {
        const bool branch_taken_0x19291c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x19291c) {
            ctx->pc = 0x19292Cu;
            goto label_19292c;
        }
    }
    ctx->pc = 0x192924u;
    // 0x192924: 0x1000fff6  b           . + 4 + (-0xA << 2)
    ctx->pc = 0x192924u;
    {
        const bool branch_taken_0x192924 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192928u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192924u;
            // 0x192928: 0x60882d  daddu       $s1, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192924) {
            ctx->pc = 0x192900u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192900;
        }
    }
    ctx->pc = 0x19292Cu;
label_19292c:
    // 0x19292c: 0x8e2300cc  lw          $v1, 0xCC($s1)
    ctx->pc = 0x19292cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 204)));
    // 0x192930: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x192930u;
    {
        const bool branch_taken_0x192930 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x192930) {
            ctx->pc = 0x192958u;
            goto label_192958;
        }
    }
    ctx->pc = 0x192938u;
    // 0x192938: 0x1000fff1  b           . + 4 + (-0xF << 2)
    ctx->pc = 0x192938u;
    {
        const bool branch_taken_0x192938 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19293Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192938u;
            // 0x19293c: 0x60882d  daddu       $s1, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192938) {
            ctx->pc = 0x192900u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192900;
        }
    }
    ctx->pc = 0x192940u;
label_192940:
    // 0x192940: 0x8e2300cc  lw          $v1, 0xCC($s1)
    ctx->pc = 0x192940u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 204)));
    // 0x192944: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x192944u;
    {
        const bool branch_taken_0x192944 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x192944) {
            ctx->pc = 0x192954u;
            goto label_192954;
        }
    }
    ctx->pc = 0x19294Cu;
    // 0x19294c: 0x1000ffec  b           . + 4 + (-0x14 << 2)
    ctx->pc = 0x19294Cu;
    {
        const bool branch_taken_0x19294c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19294Cu;
            // 0x192950: 0x60882d  daddu       $s1, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19294c) {
            ctx->pc = 0x192900u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192900;
        }
    }
    ctx->pc = 0x192954u;
label_192954:
    // 0x192954: 0x8e3100c8  lw          $s1, 0xC8($s1)
    ctx->pc = 0x192954u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 200)));
label_192958:
    // 0x192958: 0x1630fff9  bne         $s1, $s0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x192958u;
    {
        const bool branch_taken_0x192958 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 16));
        if (branch_taken_0x192958) {
            ctx->pc = 0x192940u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192940;
        }
    }
    ctx->pc = 0x192960u;
    // 0x192960: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x192960u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x192964: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x192964u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x192968: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x192968u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19296c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19296cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x192970: 0x3e00008  jr          $ra
    ctx->pc = 0x192970u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x192974u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192970u;
            // 0x192974: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192900u: goto label_192900;
            case 0x192918u: goto label_192918;
            case 0x19292Cu: goto label_19292c;
            case 0x192940u: goto label_192940;
            case 0x192954u: goto label_192954;
            case 0x192958u: goto label_192958;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192978u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
