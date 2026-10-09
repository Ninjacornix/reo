#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177240
// Address: 0x177240 - 0x1772b8
void sub_00177240_0x177240(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177240_0x177240");
#endif

    switch (ctx->pc) {
        case 0x17728cu: goto label_17728c;
        default: break;
    }

    ctx->pc = 0x177240u;

    // 0x177240: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x177240u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x177244: 0x24880cc0  addiu       $t0, $a0, 0xCC0
    ctx->pc = 0x177244u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 4), 3264));
    // 0x177248: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x177248u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17724c: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x17724cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177250: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x177250u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x177254: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x177254u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x177258: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x177258u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17725c: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x17725cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177260: 0x8d030288  lw          $v1, 0x288($t0)
    ctx->pc = 0x177260u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 648)));
    // 0x177264: 0x4610006  bgez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x177264u;
    {
        const bool branch_taken_0x177264 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x177268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177264u;
            // 0x177268: 0x2442f138  addiu       $v0, $v0, -0xEC8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963512));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177264) {
            ctx->pc = 0x177280u;
            goto label_177280;
        }
    }
    ctx->pc = 0x17726Cu;
    // 0x17726c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17726cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x177270: 0xad000288  sw          $zero, 0x288($t0)
    ctx->pc = 0x177270u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 648), GPR_U32(ctx, 0));
    // 0x177274: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x177274u;
    {
        const bool branch_taken_0x177274 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x177278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177274u;
            // 0x177278: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177274) {
            ctx->pc = 0x1772A4u;
            goto label_1772a4;
        }
    }
    ctx->pc = 0x17727Cu;
    // 0x17727c: 0x0  nop
    ctx->pc = 0x17727cu;
    // NOP
label_177280:
    // 0x177280: 0x8d060288  lw          $a2, 0x288($t0)
    ctx->pc = 0x177280u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 648)));
    // 0x177284: 0xc05407a  jal         func_1501E8
    ctx->pc = 0x177284u;
    SET_GPR_U32(ctx, 31, 0x17728Cu);
    ctx->pc = 0x177288u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177284u;
            // 0x177288: 0x8c470008  lw          $a3, 0x8($v0) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1501E8u;
    if (runtime->hasFunction(0x1501E8u)) {
        auto targetFn = runtime->lookupFunction(0x1501E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17728Cu; }
        if (ctx->pc != 0x17728Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001501E8_0x1501e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17728Cu; }
        if (ctx->pc != 0x17728Cu) { return; }
    }
    ctx->pc = 0x17728Cu;
label_17728c:
    // 0x17728c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x17728Cu;
    {
        const bool branch_taken_0x17728c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x177290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17728Cu;
            // 0x177290: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17728c) {
            ctx->pc = 0x1772A0u;
            goto label_1772a0;
        }
    }
    ctx->pc = 0x177294u;
    // 0x177294: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x177294u;
    {
        const bool branch_taken_0x177294 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x177298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177294u;
            // 0x177298: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177294) {
            ctx->pc = 0x1772A4u;
            goto label_1772a4;
        }
    }
    ctx->pc = 0x17729Cu;
    // 0x17729c: 0x0  nop
    ctx->pc = 0x17729cu;
    // NOP
label_1772a0:
    // 0x1772a0: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1772a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
label_1772a4:
    // 0x1772a4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1772a4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1772a8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1772a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1772ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1772ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1772B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1772ACu;
            // 0x1772b0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x177280u: goto label_177280;
            case 0x17728Cu: goto label_17728c;
            case 0x1772A0u: goto label_1772a0;
            case 0x1772A4u: goto label_1772a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1772B4u;
    // 0x1772b4: 0x0  nop
    ctx->pc = 0x1772b4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
