#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F968
// Address: 0x15f968 - 0x15f9d0
void sub_0015F968_0x15f968(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F968_0x15f968");
#endif

    switch (ctx->pc) {
        case 0x15f990u: goto label_15f990;
        case 0x15f9b0u: goto label_15f9b0;
        default: break;
    }

    ctx->pc = 0x15f968u;

    // 0x15f968: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15f968u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15f96c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f96cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f970: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x15f970u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f974: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15f974u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15f978: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x15f978u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f97c: 0x24040009  addiu       $a0, $zero, 0x9
    ctx->pc = 0x15f97cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x15f980: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15f980u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15f984: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x15f984u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x15f988: 0xc040c18  jal         func_103060
    ctx->pc = 0x15F988u;
    SET_GPR_U32(ctx, 31, 0x15F990u);
    ctx->pc = 0x15F98Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F988u;
            // 0x15f98c: 0xc0882d  daddu       $s1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103060u;
    if (runtime->hasFunction(0x103060u)) {
        auto targetFn = runtime->lookupFunction(0x103060u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F990u; }
        if (ctx->pc != 0x15F990u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103060_0x103060(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F990u; }
        if (ctx->pc != 0x15F990u) { return; }
    }
    ctx->pc = 0x15F990u;
label_15f990:
    // 0x15f990: 0x2604000f  addiu       $a0, $s0, 0xF
    ctx->pc = 0x15f990u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 15));
    // 0x15f994: 0x2a030000  slti        $v1, $s0, 0x0
    ctx->pc = 0x15f994u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x15f998: 0xac510080  sw          $s1, 0x80($v0)
    ctx->pc = 0x15f998u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 128), GPR_U32(ctx, 17));
    // 0x15f99c: 0x83800b  movn        $s0, $a0, $v1
    ctx->pc = 0x15f99cu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 4));
    // 0x15f9a0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x15f9a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f9a4: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x15f9a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f9a8: 0xc040cfe  jal         func_1033F8
    ctx->pc = 0x15F9A8u;
    SET_GPR_U32(ctx, 31, 0x15F9B0u);
    ctx->pc = 0x15F9ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F9A8u;
            // 0x15f9ac: 0x103103  sra         $a2, $s0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 16), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1033F8u;
    if (runtime->hasFunction(0x1033F8u)) {
        auto targetFn = runtime->lookupFunction(0x1033F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F9B0u; }
        if (ctx->pc != 0x15F9B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001033F8_0x1033f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F9B0u; }
        if (ctx->pc != 0x15F9B0u) { return; }
    }
    ctx->pc = 0x15F9B0u;
label_15f9b0:
    // 0x15f9b0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15f9b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f9b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f9b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f9b8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f9b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f9bc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15f9bcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f9c0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15f9c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15f9c4: 0x3e00008  jr          $ra
    ctx->pc = 0x15F9C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15F9C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F9C4u;
            // 0x15f9c8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F990u: goto label_15f990;
            case 0x15F9B0u: goto label_15f9b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15F9CCu;
    // 0x15f9cc: 0x0  nop
    ctx->pc = 0x15f9ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
