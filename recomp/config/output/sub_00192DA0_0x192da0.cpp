#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192DA0
// Address: 0x192da0 - 0x192dec
void sub_00192DA0_0x192da0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192DA0_0x192da0");
#endif

    switch (ctx->pc) {
        case 0x192db4u: goto label_192db4;
        default: break;
    }

    ctx->pc = 0x192da0u;

    // 0x192da0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x192da0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x192da4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x192da4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x192da8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x192da8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x192dac: 0xc063728  jal         func_18DCA0
    ctx->pc = 0x192DACu;
    SET_GPR_U32(ctx, 31, 0x192DB4u);
    ctx->pc = 0x192DB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192DACu;
            // 0x192db0: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DCA0u;
    if (runtime->hasFunction(0x18DCA0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192DB4u; }
        if (ctx->pc != 0x192DB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192DB4u; }
        if (ctx->pc != 0x192DB4u) { return; }
    }
    ctx->pc = 0x192DB4u;
label_192db4:
    // 0x192db4: 0x94430000  lhu         $v1, 0x0($v0)
    ctx->pc = 0x192db4u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x192db8: 0x30638000  andi        $v1, $v1, 0x8000
    ctx->pc = 0x192db8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)32768);
    // 0x192dbc: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x192DBCu;
    {
        const bool branch_taken_0x192dbc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x192dbc) {
            ctx->pc = 0x192DD4u;
            goto label_192dd4;
        }
    }
    ctx->pc = 0x192DC4u;
    // 0x192dc4: 0xc440000c  lwc1        $f0, 0xC($v0)
    ctx->pc = 0x192dc4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x192dc8: 0xe6000000  swc1        $f0, 0x0($s0)
    ctx->pc = 0x192dc8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 0), bits); }
    // 0x192dcc: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x192DCCu;
    {
        const bool branch_taken_0x192dcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192DD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192DCCu;
            // 0x192dd0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192dcc) {
            ctx->pc = 0x192DDCu;
            goto label_192ddc;
        }
    }
    ctx->pc = 0x192DD4u;
label_192dd4:
    // 0x192dd4: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x192dd4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x192dd8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x192dd8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_192ddc:
    // 0x192ddc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x192ddcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x192de0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x192de0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x192de4: 0x3e00008  jr          $ra
    ctx->pc = 0x192DE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x192DE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192DE4u;
            // 0x192de8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192DB4u: goto label_192db4;
            case 0x192DD4u: goto label_192dd4;
            case 0x192DDCu: goto label_192ddc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192DECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
