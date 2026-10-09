#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F660
// Address: 0x15f660 - 0x15f6d8
void sub_0015F660_0x15f660(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F660_0x15f660");
#endif

    switch (ctx->pc) {
        case 0x15f680u: goto label_15f680;
        case 0x15f6a0u: goto label_15f6a0;
        default: break;
    }

    ctx->pc = 0x15f660u;

    // 0x15f660: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15f660u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15f664: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15f664u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15f668: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x15f668u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f66c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f66cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f670: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15f670u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f674: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15f674u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15f678: 0xc042c56  jal         func_10B158
    ctx->pc = 0x15F678u;
    SET_GPR_U32(ctx, 31, 0x15F680u);
    ctx->pc = 0x15F67Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F678u;
            // 0x15f67c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F680u; }
        if (ctx->pc != 0x15F680u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F680u; }
        if (ctx->pc != 0x15F680u) { return; }
    }
    ctx->pc = 0x15F680u;
label_15f680:
    // 0x15f680: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15f680u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15f684: 0x8e030114  lw          $v1, 0x114($s0)
    ctx->pc = 0x15f684u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 276)));
    // 0x15f688: 0x2484f260  addiu       $a0, $a0, -0xDA0
    ctx->pc = 0x15f688u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963808));
    // 0x15f68c: 0x62182a  slt         $v1, $v1, $v0
    ctx->pc = 0x15f68cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x15f690: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x15F690u;
    {
        const bool branch_taken_0x15f690 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x15F694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F690u;
            // 0x15f694: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f690) {
            ctx->pc = 0x15F6C0u;
            goto label_15f6c0;
        }
    }
    ctx->pc = 0x15F698u;
    // 0x15f698: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15F698u;
    SET_GPR_U32(ctx, 31, 0x15F6A0u);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F6A0u; }
        if (ctx->pc != 0x15F6A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F6A0u; }
        if (ctx->pc != 0x15F6A0u) { return; }
    }
    ctx->pc = 0x15F6A0u;
label_15f6a0:
    // 0x15f6a0: 0x8e060114  lw          $a2, 0x114($s0)
    ctx->pc = 0x15f6a0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 276)));
    // 0x15f6a4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x15f6a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f6a8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f6a8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f6ac: 0x8e040110  lw          $a0, 0x110($s0)
    ctx->pc = 0x15f6acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 272)));
    // 0x15f6b0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15f6b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f6b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f6b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f6b8: 0x8042d7e  j           func_10B5F8
    ctx->pc = 0x15F6B8u;
    ctx->pc = 0x15F6BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F6B8u;
            // 0x15f6bc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F6C0u;
label_15f6c0:
    // 0x15f6c0: 0x8e040110  lw          $a0, 0x110($s0)
    ctx->pc = 0x15f6c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 272)));
    // 0x15f6c4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f6c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f6c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f6c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f6cc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15f6ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f6d0: 0x8042bf0  j           func_10AFC0
    ctx->pc = 0x15F6D0u;
    ctx->pc = 0x15F6D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F6D0u;
            // 0x15f6d4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F6D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
