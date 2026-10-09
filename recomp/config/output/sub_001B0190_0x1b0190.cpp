#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0190
// Address: 0x1b0190 - 0x1b0208
void sub_001B0190_0x1b0190(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0190_0x1b0190");
#endif

    switch (ctx->pc) {
        case 0x1b01a4u: goto label_1b01a4;
        case 0x1b01dcu: goto label_1b01dc;
        case 0x1b01ecu: goto label_1b01ec;
        default: break;
    }

    ctx->pc = 0x1b0190u;

    // 0x1b0190: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b0190u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b0194: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b0194u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b0198: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b0198u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b019c: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B019Cu;
    SET_GPR_U32(ctx, 31, 0x1B01A4u);
    ctx->pc = 0x1B01A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B019Cu;
            // 0x1b01a0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B01A4u; }
        if (ctx->pc != 0x1B01A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B01A4u; }
        if (ctx->pc != 0x1B01A4u) { return; }
    }
    ctx->pc = 0x1B01A4u;
label_1b01a4:
    // 0x1b01a4: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1b01a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b01a8: 0x10430012  beq         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B01A8u;
    {
        const bool branch_taken_0x1b01a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B01ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B01A8u;
            // 0x1b01ac: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b01a8) {
            ctx->pc = 0x1B01F4u;
            goto label_1b01f4;
        }
    }
    ctx->pc = 0x1B01B0u;
    // 0x1b01b0: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B01B0u;
    {
        const bool branch_taken_0x1b01b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b01b0) {
            ctx->pc = 0x1B01F4u;
            goto label_1b01f4;
        }
    }
    ctx->pc = 0x1B01B8u;
    // 0x1b01b8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b01b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b01bc: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B01BCu;
    {
        const bool branch_taken_0x1b01bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B01C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B01BCu;
            // 0x1b01c0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b01bc) {
            ctx->pc = 0x1B01E4u;
            goto label_1b01e4;
        }
    }
    ctx->pc = 0x1B01C4u;
    // 0x1b01c4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B01C4u;
    {
        const bool branch_taken_0x1b01c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B01C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B01C4u;
            // 0x1b01c8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b01c4) {
            ctx->pc = 0x1B01D4u;
            goto label_1b01d4;
        }
    }
    ctx->pc = 0x1B01CCu;
    // 0x1b01cc: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1B01CCu;
    {
        const bool branch_taken_0x1b01cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B01D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B01CCu;
            // 0x1b01d0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b01cc) {
            ctx->pc = 0x1B01F8u;
            goto label_1b01f8;
        }
    }
    ctx->pc = 0x1B01D4u;
label_1b01d4:
    // 0x1b01d4: 0xc204728  jal         func_811CA0
    ctx->pc = 0x1B01D4u;
    SET_GPR_U32(ctx, 31, 0x1B01DCu);
    ctx->pc = 0x811CA0u;
    {
        auto targetFn = runtime->lookupFunction(0x811CA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B01DCu; }
        if (ctx->pc != 0x1B01DCu) { return; }
    }
    ctx->pc = 0x1B01DCu;
label_1b01dc:
    // 0x1b01dc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1B01DCu;
    {
        const bool branch_taken_0x1b01dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B01E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B01DCu;
            // 0x1b01e0: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b01dc) {
            ctx->pc = 0x1B01FCu;
            goto label_1b01fc;
        }
    }
    ctx->pc = 0x1B01E4u;
label_1b01e4:
    // 0x1b01e4: 0xc204554  jal         func_811550
    ctx->pc = 0x1B01E4u;
    SET_GPR_U32(ctx, 31, 0x1B01ECu);
    ctx->pc = 0x811550u;
    {
        auto targetFn = runtime->lookupFunction(0x811550u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B01ECu; }
        if (ctx->pc != 0x1B01ECu) { return; }
    }
    ctx->pc = 0x1B01ECu;
label_1b01ec:
    // 0x1b01ec: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1B01ECu;
    {
        const bool branch_taken_0x1b01ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b01ec) {
            ctx->pc = 0x1B01F8u;
            goto label_1b01f8;
        }
    }
    ctx->pc = 0x1B01F4u;
label_1b01f4:
    // 0x1b01f4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b01f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b01f8:
    // 0x1b01f8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b01f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1b01fc:
    // 0x1b01fc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b01fcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b0200: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0200u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0200u;
            // 0x1b0204: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B01A4u: goto label_1b01a4;
            case 0x1B01D4u: goto label_1b01d4;
            case 0x1B01DCu: goto label_1b01dc;
            case 0x1B01E4u: goto label_1b01e4;
            case 0x1B01ECu: goto label_1b01ec;
            case 0x1B01F4u: goto label_1b01f4;
            case 0x1B01F8u: goto label_1b01f8;
            case 0x1B01FCu: goto label_1b01fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0208u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
