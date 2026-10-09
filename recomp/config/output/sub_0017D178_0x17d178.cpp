#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D178
// Address: 0x17d178 - 0x17d1c8
void sub_0017D178_0x17d178(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D178_0x17d178");
#endif

    switch (ctx->pc) {
        case 0x17d19cu: goto label_17d19c;
        case 0x17d1a4u: goto label_17d1a4;
        default: break;
    }

    ctx->pc = 0x17d178u;

    // 0x17d178: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d178u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d17c: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x17d17cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d180: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17d180u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17d184: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x17D184u;
    {
        const bool branch_taken_0x17d184 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17D188u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D184u;
            // 0x17d188: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17d184) {
            ctx->pc = 0x17D1B8u;
            goto label_17d1b8;
        }
    }
    ctx->pc = 0x17D18Cu;
    // 0x17d18c: 0x8c440024  lw          $a0, 0x24($v0)
    ctx->pc = 0x17d18cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 36)));
    // 0x17d190: 0x8c500030  lw          $s0, 0x30($v0)
    ctx->pc = 0x17d190u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 48)));
    // 0x17d194: 0xc05f600  jal         func_17D800
    ctx->pc = 0x17D194u;
    SET_GPR_U32(ctx, 31, 0x17D19Cu);
    ctx->pc = 0x17D198u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D194u;
            // 0x17d198: 0xac400000  sw          $zero, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D800u;
    if (runtime->hasFunction(0x17D800u)) {
        auto targetFn = runtime->lookupFunction(0x17D800u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D19Cu; }
        if (ctx->pc != 0x17D19Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D800_0x17d800(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D19Cu; }
        if (ctx->pc != 0x17D19Cu) { return; }
    }
    ctx->pc = 0x17D19Cu;
label_17d19c:
    // 0x17d19c: 0xc05e9d4  jal         func_17A750
    ctx->pc = 0x17D19Cu;
    SET_GPR_U32(ctx, 31, 0x17D1A4u);
    ctx->pc = 0x17D1A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D19Cu;
            // 0x17d1a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A750u;
    if (runtime->hasFunction(0x17A750u)) {
        auto targetFn = runtime->lookupFunction(0x17A750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D1A4u; }
        if (ctx->pc != 0x17D1A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A750_0x17a750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D1A4u; }
        if (ctx->pc != 0x17D1A4u) { return; }
    }
    ctx->pc = 0x17D1A4u;
label_17d1a4:
    // 0x17d1a4: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x17d1a4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x17d1a8: 0x2463f2a0  addiu       $v1, $v1, -0xD60
    ctx->pc = 0x17d1a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294963872));
    // 0x17d1ac: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x17d1acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x17d1b0: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x17d1b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x17d1b4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x17d1b4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_17d1b8:
    // 0x17d1b8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17d1b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d1bc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17d1bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17d1c0: 0x3e00008  jr          $ra
    ctx->pc = 0x17D1C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D1C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D1C0u;
            // 0x17d1c4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D19Cu: goto label_17d19c;
            case 0x17D1A4u: goto label_17d1a4;
            case 0x17D1B8u: goto label_17d1b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D1C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
