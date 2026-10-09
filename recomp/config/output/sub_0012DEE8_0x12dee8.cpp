#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012DEE8
// Address: 0x12dee8 - 0x12df4c
void sub_0012DEE8_0x12dee8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012DEE8_0x12dee8");
#endif

    switch (ctx->pc) {
        case 0x12df28u: goto label_12df28;
        default: break;
    }

    ctx->pc = 0x12dee8u;

    // 0x12dee8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12dee8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12deec: 0x100582d  daddu       $t3, $t0, $zero
    ctx->pc = 0x12deecu;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12def0: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x12def0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x12def4: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x12def4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12def8: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x12def8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x12defc: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x12defcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12df00: 0xafa90000  sw          $t1, 0x0($sp)
    ctx->pc = 0x12df00u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 9));
    // 0x12df04: 0x27a90014  addiu       $t1, $sp, 0x14
    ctx->pc = 0x12df04u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    // 0x12df08: 0x27a20018  addiu       $v0, $sp, 0x18
    ctx->pc = 0x12df08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x12df0c: 0x27a80013  addiu       $t0, $sp, 0x13
    ctx->pc = 0x12df0cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 19));
    // 0x12df10: 0x27a60010  addiu       $a2, $sp, 0x10
    ctx->pc = 0x12df10u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x12df14: 0x27a70012  addiu       $a3, $sp, 0x12
    ctx->pc = 0x12df14u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 18));
    // 0x12df18: 0x27aa0015  addiu       $t2, $sp, 0x15
    ctx->pc = 0x12df18u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 29), 21));
    // 0x12df1c: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x12df1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x12df20: 0xc0499e6  jal         func_126798
    ctx->pc = 0x12DF20u;
    SET_GPR_U32(ctx, 31, 0x12DF28u);
    ctx->pc = 0x12DF24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12DF20u;
            // 0x12df24: 0xafa20008  sw          $v0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126798u;
    if (runtime->hasFunction(0x126798u)) {
        auto targetFn = runtime->lookupFunction(0x126798u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12DF28u; }
        if (ctx->pc != 0x12DF28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126798_0x126798(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12DF28u; }
        if (ctx->pc != 0x12DF28u) { return; }
    }
    ctx->pc = 0x12DF28u;
label_12df28:
    // 0x12df28: 0x83a30015  lb          $v1, 0x15($sp)
    ctx->pc = 0x12df28u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 21)));
    // 0x12df2c: 0x83a40013  lb          $a0, 0x13($sp)
    ctx->pc = 0x12df2cu;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 19)));
    // 0x12df30: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x12df30u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x12df34: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x12df34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12df38: 0xae240000  sw          $a0, 0x0($s1)
    ctx->pc = 0x12df38u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 4));
    // 0x12df3c: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x12df3cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12df40: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x12df40u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12df44: 0x3e00008  jr          $ra
    ctx->pc = 0x12DF44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12DF48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DF44u;
            // 0x12df48: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12DF28u: goto label_12df28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12DF4Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
