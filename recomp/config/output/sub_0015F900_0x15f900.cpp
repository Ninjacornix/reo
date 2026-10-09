#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F900
// Address: 0x15f900 - 0x15f968
void sub_0015F900_0x15f900(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F900_0x15f900");
#endif

    switch (ctx->pc) {
        case 0x15f928u: goto label_15f928;
        case 0x15f948u: goto label_15f948;
        default: break;
    }

    ctx->pc = 0x15f900u;

    // 0x15f900: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15f900u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15f904: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f904u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f908: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x15f908u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f90c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15f90cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15f910: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x15f910u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f914: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x15f914u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x15f918: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15f918u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15f91c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x15f91cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x15f920: 0xc040c18  jal         func_103060
    ctx->pc = 0x15F920u;
    SET_GPR_U32(ctx, 31, 0x15F928u);
    ctx->pc = 0x15F924u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F920u;
            // 0x15f924: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103060u;
    if (runtime->hasFunction(0x103060u)) {
        auto targetFn = runtime->lookupFunction(0x103060u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F928u; }
        if (ctx->pc != 0x15F928u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103060_0x103060(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F928u; }
        if (ctx->pc != 0x15F928u) { return; }
    }
    ctx->pc = 0x15F928u;
label_15f928:
    // 0x15f928: 0x2604000f  addiu       $a0, $s0, 0xF
    ctx->pc = 0x15f928u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 15));
    // 0x15f92c: 0x2a030000  slti        $v1, $s0, 0x0
    ctx->pc = 0x15f92cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x15f930: 0xac510080  sw          $s1, 0x80($v0)
    ctx->pc = 0x15f930u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 128), GPR_U32(ctx, 17));
    // 0x15f934: 0x83800b  movn        $s0, $a0, $v1
    ctx->pc = 0x15f934u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 4));
    // 0x15f938: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x15f938u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f93c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x15f93cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f940: 0xc040d4c  jal         func_103530
    ctx->pc = 0x15F940u;
    SET_GPR_U32(ctx, 31, 0x15F948u);
    ctx->pc = 0x15F944u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F940u;
            // 0x15f944: 0x103103  sra         $a2, $s0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 16), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103530u;
    if (runtime->hasFunction(0x103530u)) {
        auto targetFn = runtime->lookupFunction(0x103530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F948u; }
        if (ctx->pc != 0x15F948u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103530_0x103530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F948u; }
        if (ctx->pc != 0x15F948u) { return; }
    }
    ctx->pc = 0x15F948u;
label_15f948:
    // 0x15f948: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15f948u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f94c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f94cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f950: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f950u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f954: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15f954u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f958: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15f958u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15f95c: 0x3e00008  jr          $ra
    ctx->pc = 0x15F95Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15F960u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F95Cu;
            // 0x15f960: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F928u: goto label_15f928;
            case 0x15F948u: goto label_15f948;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15F964u;
    // 0x15f964: 0x0  nop
    ctx->pc = 0x15f964u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
