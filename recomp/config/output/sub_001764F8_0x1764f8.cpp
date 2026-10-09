#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001764F8
// Address: 0x1764f8 - 0x176554
void sub_001764F8_0x1764f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001764F8_0x1764f8");
#endif

    switch (ctx->pc) {
        case 0x17651cu: goto label_17651c;
        default: break;
    }

    ctx->pc = 0x1764f8u;

    // 0x1764f8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1764f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1764fc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1764fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x176500: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x176500u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176504: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x176504u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x176508: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x176508u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17650c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17650cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x176510: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x176510u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x176514: 0xc05d99c  jal         func_176670
    ctx->pc = 0x176514u;
    SET_GPR_U32(ctx, 31, 0x17651Cu);
    ctx->pc = 0x176518u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176514u;
            // 0x176518: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176670u;
    if (runtime->hasFunction(0x176670u)) {
        auto targetFn = runtime->lookupFunction(0x176670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17651Cu; }
        if (ctx->pc != 0x17651Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176670_0x176670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17651Cu; }
        if (ctx->pc != 0x17651Cu) { return; }
    }
    ctx->pc = 0x17651Cu;
label_17651c:
    // 0x17651c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x17651Cu;
    {
        const bool branch_taken_0x17651c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x176520u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17651Cu;
            // 0x176520: 0x26100cc0  addiu       $s0, $s0, 0xCC0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 3264));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17651c) {
            ctx->pc = 0x17653Cu;
            goto label_17653c;
        }
    }
    ctx->pc = 0x176524u;
    // 0x176524: 0x8e030264  lw          $v1, 0x264($s0)
    ctx->pc = 0x176524u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 612)));
    // 0x176528: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x176528u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x17652c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x17652cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176530: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x176530u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x176534: 0x8c83f140  lw          $v1, -0xEC0($a0)
    ctx->pc = 0x176534u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294963520)));
    // 0x176538: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x176538u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_17653c:
    // 0x17653c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17653cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176540: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x176540u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176544: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x176544u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176548: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x176548u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17654c: 0x3e00008  jr          $ra
    ctx->pc = 0x17654Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17654Cu;
            // 0x176550: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17651Cu: goto label_17651c;
            case 0x17653Cu: goto label_17653c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176554u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
