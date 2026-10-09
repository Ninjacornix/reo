#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013A180
// Address: 0x13a180 - 0x13a244
void sub_0013A180_0x13a180(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013A180_0x13a180");
#endif

    switch (ctx->pc) {
        case 0x13a1f8u: goto label_13a1f8;
        case 0x13a208u: goto label_13a208;
        case 0x13a218u: goto label_13a218;
        case 0x13a228u: goto label_13a228;
        default: break;
    }

    ctx->pc = 0x13a180u;

    // 0x13a180: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13a180u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13a184: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x13a184u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a188: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13a188u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13a18c: 0x1080002a  beqz        $a0, . + 4 + (0x2A << 2)
    ctx->pc = 0x13A18Cu;
    {
        const bool branch_taken_0x13a18c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x13A190u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A18Cu;
            // 0x13a190: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a18c) {
            ctx->pc = 0x13A238u;
            goto label_13a238;
        }
    }
    ctx->pc = 0x13A194u;
    // 0x13a194: 0x240200cb  addiu       $v0, $zero, 0xCB
    ctx->pc = 0x13a194u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 203));
    // 0x13a198: 0x10a20021  beq         $a1, $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x13A198u;
    {
        const bool branch_taken_0x13a198 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x13A19Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A198u;
            // 0x13a19c: 0x28a200cc  slti        $v0, $a1, 0xCC (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)204) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a198) {
            ctx->pc = 0x13A220u;
            goto label_13a220;
        }
    }
    ctx->pc = 0x13A1A0u;
    // 0x13a1a0: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x13A1A0u;
    {
        const bool branch_taken_0x13a1a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13A1A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A1A0u;
            // 0x13a1a4: 0x240200cd  addiu       $v0, $zero, 0xCD (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 205));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a1a0) {
            ctx->pc = 0x13A1D0u;
            goto label_13a1d0;
        }
    }
    ctx->pc = 0x13A1A8u;
    // 0x13a1a8: 0x240200c9  addiu       $v0, $zero, 0xC9
    ctx->pc = 0x13a1a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 201));
    // 0x13a1ac: 0x10a20014  beq         $a1, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x13A1ACu;
    {
        const bool branch_taken_0x13a1ac = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x13A1B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A1ACu;
            // 0x13a1b0: 0x28a200ca  slti        $v0, $a1, 0xCA (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)202) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a1ac) {
            ctx->pc = 0x13A200u;
            goto label_13a200;
        }
    }
    ctx->pc = 0x13A1B4u;
    // 0x13a1b4: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x13A1B4u;
    {
        const bool branch_taken_0x13a1b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13A1B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A1B4u;
            // 0x13a1b8: 0x240200c8  addiu       $v0, $zero, 0xC8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 200));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a1b4) {
            ctx->pc = 0x13A210u;
            goto label_13a210;
        }
    }
    ctx->pc = 0x13A1BCu;
    // 0x13a1bc: 0x10a2000c  beq         $a1, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x13A1BCu;
    {
        const bool branch_taken_0x13a1bc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x13A1C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A1BCu;
            // 0x13a1c0: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a1bc) {
            ctx->pc = 0x13A1F0u;
            goto label_13a1f0;
        }
    }
    ctx->pc = 0x13A1C4u;
    // 0x13a1c4: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x13A1C4u;
    {
        const bool branch_taken_0x13a1c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13A1C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A1C4u;
            // 0x13a1c8: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a1c4) {
            ctx->pc = 0x13A23Cu;
            goto label_13a23c;
        }
    }
    ctx->pc = 0x13A1CCu;
    // 0x13a1cc: 0x0  nop
    ctx->pc = 0x13a1ccu;
    // NOP
label_13a1d0:
    // 0x13a1d0: 0x10a20013  beq         $a1, $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x13A1D0u;
    {
        const bool branch_taken_0x13a1d0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x13A1D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A1D0u;
            // 0x13a1d4: 0x28a200cd  slti        $v0, $a1, 0xCD (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)205) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a1d0) {
            ctx->pc = 0x13A220u;
            goto label_13a220;
        }
    }
    ctx->pc = 0x13A1D8u;
    // 0x13a1d8: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x13A1D8u;
    {
        const bool branch_taken_0x13a1d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13A1DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A1D8u;
            // 0x13a1dc: 0x2402012b  addiu       $v0, $zero, 0x12B (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 299));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a1d8) {
            ctx->pc = 0x13A210u;
            goto label_13a210;
        }
    }
    ctx->pc = 0x13A1E0u;
    // 0x13a1e0: 0x10a20013  beq         $a1, $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x13A1E0u;
    {
        const bool branch_taken_0x13a1e0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x13A1E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A1E0u;
            // 0x13a1e4: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a1e0) {
            ctx->pc = 0x13A230u;
            goto label_13a230;
        }
    }
    ctx->pc = 0x13A1E8u;
    // 0x13a1e8: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x13A1E8u;
    {
        const bool branch_taken_0x13a1e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13A1ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A1E8u;
            // 0x13a1ec: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a1e8) {
            ctx->pc = 0x13A23Cu;
            goto label_13a23c;
        }
    }
    ctx->pc = 0x13A1F0u;
label_13a1f0:
    // 0x13a1f0: 0xc04e84c  jal         func_13A130
    ctx->pc = 0x13A1F0u;
    SET_GPR_U32(ctx, 31, 0x13A1F8u);
    ctx->pc = 0x13A130u;
    if (runtime->hasFunction(0x13A130u)) {
        auto targetFn = runtime->lookupFunction(0x13A130u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A1F8u; }
        if (ctx->pc != 0x13A1F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A130_0x13a130(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A1F8u; }
        if (ctx->pc != 0x13A1F8u) { return; }
    }
    ctx->pc = 0x13A1F8u;
label_13a1f8:
    // 0x13a1f8: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x13A1F8u;
    {
        const bool branch_taken_0x13a1f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13A1FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A1F8u;
            // 0x13a1fc: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a1f8) {
            ctx->pc = 0x13A234u;
            goto label_13a234;
        }
    }
    ctx->pc = 0x13A200u;
label_13a200:
    // 0x13a200: 0xc04e850  jal         func_13A140
    ctx->pc = 0x13A200u;
    SET_GPR_U32(ctx, 31, 0x13A208u);
    ctx->pc = 0x13A140u;
    if (runtime->hasFunction(0x13A140u)) {
        auto targetFn = runtime->lookupFunction(0x13A140u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A208u; }
        if (ctx->pc != 0x13A208u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A140_0x13a140(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A208u; }
        if (ctx->pc != 0x13A208u) { return; }
    }
    ctx->pc = 0x13A208u;
label_13a208:
    // 0x13a208: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x13A208u;
    {
        const bool branch_taken_0x13a208 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13A20Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A208u;
            // 0x13a20c: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a208) {
            ctx->pc = 0x13A234u;
            goto label_13a234;
        }
    }
    ctx->pc = 0x13A210u;
label_13a210:
    // 0x13a210: 0xc04e858  jal         func_13A160
    ctx->pc = 0x13A210u;
    SET_GPR_U32(ctx, 31, 0x13A218u);
    ctx->pc = 0x13A160u;
    if (runtime->hasFunction(0x13A160u)) {
        auto targetFn = runtime->lookupFunction(0x13A160u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A218u; }
        if (ctx->pc != 0x13A218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A160_0x13a160(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A218u; }
        if (ctx->pc != 0x13A218u) { return; }
    }
    ctx->pc = 0x13A218u;
label_13a218:
    // 0x13a218: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x13A218u;
    {
        const bool branch_taken_0x13a218 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13A21Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A218u;
            // 0x13a21c: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a218) {
            ctx->pc = 0x13A234u;
            goto label_13a234;
        }
    }
    ctx->pc = 0x13A220u;
label_13a220:
    // 0x13a220: 0xc04e85a  jal         func_13A168
    ctx->pc = 0x13A220u;
    SET_GPR_U32(ctx, 31, 0x13A228u);
    ctx->pc = 0x13A168u;
    if (runtime->hasFunction(0x13A168u)) {
        auto targetFn = runtime->lookupFunction(0x13A168u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A228u; }
        if (ctx->pc != 0x13A228u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A168_0x13a168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A228u; }
        if (ctx->pc != 0x13A228u) { return; }
    }
    ctx->pc = 0x13A228u;
label_13a228:
    // 0x13a228: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x13A228u;
    {
        const bool branch_taken_0x13a228 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13A22Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A228u;
            // 0x13a22c: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a228) {
            ctx->pc = 0x13A234u;
            goto label_13a234;
        }
    }
    ctx->pc = 0x13A230u;
label_13a230:
    // 0x13a230: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x13a230u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_13a234:
    // 0x13a234: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x13a234u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_13a238:
    // 0x13a238: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13a238u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13a23c:
    // 0x13a23c: 0x3e00008  jr          $ra
    ctx->pc = 0x13A23Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13A240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A23Cu;
            // 0x13a240: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13A1D0u: goto label_13a1d0;
            case 0x13A1F0u: goto label_13a1f0;
            case 0x13A1F8u: goto label_13a1f8;
            case 0x13A200u: goto label_13a200;
            case 0x13A208u: goto label_13a208;
            case 0x13A210u: goto label_13a210;
            case 0x13A218u: goto label_13a218;
            case 0x13A220u: goto label_13a220;
            case 0x13A228u: goto label_13a228;
            case 0x13A230u: goto label_13a230;
            case 0x13A234u: goto label_13a234;
            case 0x13A238u: goto label_13a238;
            case 0x13A23Cu: goto label_13a23c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13A244u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
