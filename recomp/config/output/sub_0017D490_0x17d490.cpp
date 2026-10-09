#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D490
// Address: 0x17d490 - 0x17d4f0
void sub_0017D490_0x17d490(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D490_0x17d490");
#endif

    switch (ctx->pc) {
        case 0x17d4c4u: goto label_17d4c4;
        case 0x17d4d0u: goto label_17d4d0;
        default: break;
    }

    ctx->pc = 0x17d490u;

    // 0x17d490: 0x517c2  srl         $v0, $a1, 31
    ctx->pc = 0x17d490u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 31));
    // 0x17d494: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17d494u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17d498: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x17d498u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x17d49c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17d49cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17d4a0: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x17d4a0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x17d4a4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17d4a4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d4a8: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x17d4a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x17d4ac: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17d4acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17d4b0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x17d4b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d4b4: 0x26040004  addiu       $a0, $s0, 0x4
    ctx->pc = 0x17d4b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x17d4b8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x17d4b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x17d4bc: 0xc05f53c  jal         func_17D4F0
    ctx->pc = 0x17D4BCu;
    SET_GPR_U32(ctx, 31, 0x17D4C4u);
    ctx->pc = 0x17D4C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D4BCu;
            // 0x17d4c0: 0x28843  sra         $s1, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 2), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D4F0u;
    if (runtime->hasFunction(0x17D4F0u)) {
        auto targetFn = runtime->lookupFunction(0x17D4F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D4C4u; }
        if (ctx->pc != 0x17D4C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D4F0_0x17d4f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D4C4u; }
        if (ctx->pc != 0x17D4C4u) { return; }
    }
    ctx->pc = 0x17D4C4u;
label_17d4c4:
    // 0x17d4c4: 0x26040014  addiu       $a0, $s0, 0x14
    ctx->pc = 0x17d4c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x17d4c8: 0xc05f53c  jal         func_17D4F0
    ctx->pc = 0x17D4C8u;
    SET_GPR_U32(ctx, 31, 0x17D4D0u);
    ctx->pc = 0x17D4CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D4C8u;
            // 0x17d4cc: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D4F0u;
    if (runtime->hasFunction(0x17D4F0u)) {
        auto targetFn = runtime->lookupFunction(0x17D4F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D4D0u; }
        if (ctx->pc != 0x17D4D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D4F0_0x17d4f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D4D0u; }
        if (ctx->pc != 0x17D4D0u) { return; }
    }
    ctx->pc = 0x17D4D0u;
label_17d4d0:
    // 0x17d4d0: 0x26040024  addiu       $a0, $s0, 0x24
    ctx->pc = 0x17d4d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 36));
    // 0x17d4d4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17d4d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d4d8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17d4d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17d4dc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17d4dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d4e0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x17d4e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17d4e4: 0x805f53c  j           func_17D4F0
    ctx->pc = 0x17D4E4u;
    ctx->pc = 0x17D4E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D4E4u;
            // 0x17d4e8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D4F0u;
    if (runtime->hasFunction(0x17D4F0u)) {
        auto targetFn = runtime->lookupFunction(0x17D4F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D4F0_0x17d4f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17D4ECu;
    // 0x17d4ec: 0x0  nop
    ctx->pc = 0x17d4ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
