#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161978
// Address: 0x161978 - 0x1619d8
void sub_00161978_0x161978(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161978_0x161978");
#endif

    switch (ctx->pc) {
        case 0x16198cu: goto label_16198c;
        case 0x1619bcu: goto label_1619bc;
        default: break;
    }

    ctx->pc = 0x161978u;

    // 0x161978: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x161978u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16197c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16197cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x161980: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x161980u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x161984: 0xc05862c  jal         func_1618B0
    ctx->pc = 0x161984u;
    SET_GPR_U32(ctx, 31, 0x16198Cu);
    ctx->pc = 0x161988u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161984u;
            // 0x161988: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1618B0u;
    if (runtime->hasFunction(0x1618B0u)) {
        auto targetFn = runtime->lookupFunction(0x1618B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16198Cu; }
        if (ctx->pc != 0x16198Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001618B0_0x1618b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16198Cu; }
        if (ctx->pc != 0x16198Cu) { return; }
    }
    ctx->pc = 0x16198Cu;
label_16198c:
    // 0x16198c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x16198cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x161990: 0x54430003  bnel        $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x161990u;
    {
        const bool branch_taken_0x161990 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x161990) {
            ctx->pc = 0x161994u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x161990u;
            // 0x161994: 0x8e0300e8  lw          $v1, 0xE8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 232)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1619A0u;
            goto label_1619a0;
        }
    }
    ctx->pc = 0x161998u;
    // 0x161998: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x161998u;
    {
        const bool branch_taken_0x161998 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16199Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161998u;
            // 0x16199c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161998) {
            ctx->pc = 0x1619C8u;
            goto label_1619c8;
        }
    }
    ctx->pc = 0x1619A0u;
label_1619a0:
    // 0x1619a0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1619a0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1619a4: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1619A4u;
    {
        const bool branch_taken_0x1619a4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1619A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1619A4u;
            // 0x1619a8: 0x60302d  daddu       $a2, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1619a4) {
            ctx->pc = 0x1619C8u;
            goto label_1619c8;
        }
    }
    ctx->pc = 0x1619ACu;
    // 0x1619ac: 0x8e040040  lw          $a0, 0x40($s0)
    ctx->pc = 0x1619acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x1619b0: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1619b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1619b4: 0xc05e244  jal         func_178910
    ctx->pc = 0x1619B4u;
    SET_GPR_U32(ctx, 31, 0x1619BCu);
    ctx->pc = 0x1619B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1619B4u;
            // 0x1619b8: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178910u;
    if (runtime->hasFunction(0x178910u)) {
        auto targetFn = runtime->lookupFunction(0x178910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1619BCu; }
        if (ctx->pc != 0x1619BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178910_0x178910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1619BCu; }
        if (ctx->pc != 0x1619BCu) { return; }
    }
    ctx->pc = 0x1619BCu;
label_1619bc:
    // 0x1619bc: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1619bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1619c0: 0x2180a  movz        $v1, $zero, $v0
    ctx->pc = 0x1619c0u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
    // 0x1619c4: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1619c4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_1619c8:
    // 0x1619c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1619c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1619cc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1619ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1619d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1619D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1619D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1619D0u;
            // 0x1619d4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16198Cu: goto label_16198c;
            case 0x1619A0u: goto label_1619a0;
            case 0x1619BCu: goto label_1619bc;
            case 0x1619C8u: goto label_1619c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1619D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
