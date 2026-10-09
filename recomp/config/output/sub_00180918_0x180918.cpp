#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00180918
// Address: 0x180918 - 0x180970
void sub_00180918_0x180918(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00180918_0x180918");
#endif

    switch (ctx->pc) {
        case 0x18092cu: goto label_18092c;
        default: break;
    }

    ctx->pc = 0x180918u;

    // 0x180918: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x180918u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18091c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x18091cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x180920: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x180920u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x180924: 0xc062364  jal         func_188D90
    ctx->pc = 0x180924u;
    SET_GPR_U32(ctx, 31, 0x18092Cu);
    ctx->pc = 0x180928u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180924u;
            // 0x180928: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188D90u;
    if (runtime->hasFunction(0x188D90u)) {
        auto targetFn = runtime->lookupFunction(0x188D90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18092Cu; }
        if (ctx->pc != 0x18092Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188D90_0x188d90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18092Cu; }
        if (ctx->pc != 0x18092Cu) { return; }
    }
    ctx->pc = 0x18092Cu;
label_18092c:
    // 0x18092c: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x18092cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180930: 0x4e0000a  bltz        $a3, . + 4 + (0xA << 2)
    ctx->pc = 0x180930u;
    {
        const bool branch_taken_0x180930 = (GPR_S64(ctx, 7) < 0);
        ctx->pc = 0x180934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180930u;
            // 0x180934: 0x24040334  addiu       $a0, $zero, 0x334 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 820));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180930) {
            ctx->pc = 0x18095Cu;
            goto label_18095c;
        }
    }
    ctx->pc = 0x180938u;
    // 0x180938: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x180938u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x18093c: 0x2042018  mult        $a0, $s0, $a0
    ctx->pc = 0x18093cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x180940: 0x24636188  addiu       $v1, $v1, 0x6188
    ctx->pc = 0x180940u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 24968));
    // 0x180944: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x180944u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x180948: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x180948u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18094c: 0x642821  addu        $a1, $v1, $a0
    ctx->pc = 0x18094cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x180950: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x180950u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180954: 0xaca7000c  sw          $a3, 0xC($a1)
    ctx->pc = 0x180954u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 7));
    // 0x180958: 0xac660004  sw          $a2, 0x4($v1)
    ctx->pc = 0x180958u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 6));
label_18095c:
    // 0x18095c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x18095cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x180960: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x180960u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x180964: 0x3e00008  jr          $ra
    ctx->pc = 0x180964u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180968u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180964u;
            // 0x180968: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18092Cu: goto label_18092c;
            case 0x18095Cu: goto label_18095c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18096Cu;
    // 0x18096c: 0x0  nop
    ctx->pc = 0x18096cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
