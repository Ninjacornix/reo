#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163078
// Address: 0x163078 - 0x1632c0
void sub_00163078_0x163078(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163078_0x163078");
#endif

    switch (ctx->pc) {
        case 0x163094u: goto label_163094;
        case 0x1630a8u: goto label_1630a8;
        case 0x1630c4u: goto label_1630c4;
        case 0x1630f4u: goto label_1630f4;
        case 0x163108u: goto label_163108;
        case 0x163124u: goto label_163124;
        case 0x163154u: goto label_163154;
        case 0x163168u: goto label_163168;
        case 0x163184u: goto label_163184;
        case 0x1631d8u: goto label_1631d8;
        case 0x1631e8u: goto label_1631e8;
        case 0x163208u: goto label_163208;
        case 0x16322cu: goto label_16322c;
        case 0x163254u: goto label_163254;
        case 0x163280u: goto label_163280;
        case 0x163298u: goto label_163298;
        default: break;
    }

    ctx->pc = 0x163078u;

    // 0x163078: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x163078u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16307c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16307cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x163080: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x163080u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163084: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x163084u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x163088: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x163088u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x16308c: 0xc058d10  jal         func_163440
    ctx->pc = 0x16308Cu;
    SET_GPR_U32(ctx, 31, 0x163094u);
    ctx->pc = 0x163090u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16308Cu;
            // 0x163090: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163440u;
    if (runtime->hasFunction(0x163440u)) {
        auto targetFn = runtime->lookupFunction(0x163440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163094u; }
        if (ctx->pc != 0x163094u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163440_0x163440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163094u; }
        if (ctx->pc != 0x163094u) { return; }
    }
    ctx->pc = 0x163094u;
label_163094:
    // 0x163094: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x163094u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x163098: 0x5443000b  bnel        $v0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x163098u;
    {
        const bool branch_taken_0x163098 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x163098) {
            ctx->pc = 0x16309Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x163098u;
            // 0x16309c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1630C8u;
            goto label_1630c8;
        }
    }
    ctx->pc = 0x1630A0u;
    // 0x1630a0: 0xc058d08  jal         func_163420
    ctx->pc = 0x1630A0u;
    SET_GPR_U32(ctx, 31, 0x1630A8u);
    ctx->pc = 0x163420u;
    if (runtime->hasFunction(0x163420u)) {
        auto targetFn = runtime->lookupFunction(0x163420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1630A8u; }
        if (ctx->pc != 0x1630A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163420_0x163420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1630A8u; }
        if (ctx->pc != 0x1630A8u) { return; }
    }
    ctx->pc = 0x1630A8u;
label_1630a8:
    // 0x1630a8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1630A8u;
    {
        const bool branch_taken_0x1630a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1630ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1630A8u;
            // 0x1630ac: 0x8e040014  lw          $a0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1630a8) {
            ctx->pc = 0x1630C4u;
            goto label_1630c4;
        }
    }
    ctx->pc = 0x1630B0u;
    // 0x1630b0: 0x8c420024  lw          $v0, 0x24($v0)
    ctx->pc = 0x1630b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 36)));
    // 0x1630b4: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x1630B4u;
    {
        const bool branch_taken_0x1630b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1630b4) {
            ctx->pc = 0x1630B8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1630B4u;
            // 0x1630b8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1630C8u;
            goto label_1630c8;
        }
    }
    ctx->pc = 0x1630BCu;
    // 0x1630bc: 0x40f809  jalr        $v0
    ctx->pc = 0x1630BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1630C4u);
        ctx->pc = 0x1630C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1630BCu;
            // 0x1630c0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1630C4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163094u: goto label_163094;
            case 0x1630A8u: goto label_1630a8;
            case 0x1630C4u: goto label_1630c4;
            case 0x1630C8u: goto label_1630c8;
            case 0x1630F4u: goto label_1630f4;
            case 0x163108u: goto label_163108;
            case 0x163124u: goto label_163124;
            case 0x163128u: goto label_163128;
            case 0x163154u: goto label_163154;
            case 0x163168u: goto label_163168;
            case 0x163184u: goto label_163184;
            case 0x163188u: goto label_163188;
            case 0x16318Cu: goto label_16318c;
            case 0x1631D8u: goto label_1631d8;
            case 0x1631E8u: goto label_1631e8;
            case 0x163208u: goto label_163208;
            case 0x16322Cu: goto label_16322c;
            case 0x163248u: goto label_163248;
            case 0x163254u: goto label_163254;
            case 0x163278u: goto label_163278;
            case 0x163280u: goto label_163280;
            case 0x163288u: goto label_163288;
            case 0x163298u: goto label_163298;
            case 0x16329Cu: goto label_16329c;
            case 0x1632A0u: goto label_1632a0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1630C4u; }
            if (ctx->pc != 0x1630C4u) { return; }
        }
        }
    }
    ctx->pc = 0x1630C4u;
label_1630c4:
    // 0x1630c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1630c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1630c8:
    // 0x1630c8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1630c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1630cc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1630ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1630d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1630D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1630D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1630D0u;
            // 0x1630d4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163094u: goto label_163094;
            case 0x1630A8u: goto label_1630a8;
            case 0x1630C4u: goto label_1630c4;
            case 0x1630C8u: goto label_1630c8;
            case 0x1630F4u: goto label_1630f4;
            case 0x163108u: goto label_163108;
            case 0x163124u: goto label_163124;
            case 0x163128u: goto label_163128;
            case 0x163154u: goto label_163154;
            case 0x163168u: goto label_163168;
            case 0x163184u: goto label_163184;
            case 0x163188u: goto label_163188;
            case 0x16318Cu: goto label_16318c;
            case 0x1631D8u: goto label_1631d8;
            case 0x1631E8u: goto label_1631e8;
            case 0x163208u: goto label_163208;
            case 0x16322Cu: goto label_16322c;
            case 0x163248u: goto label_163248;
            case 0x163254u: goto label_163254;
            case 0x163278u: goto label_163278;
            case 0x163280u: goto label_163280;
            case 0x163288u: goto label_163288;
            case 0x163298u: goto label_163298;
            case 0x16329Cu: goto label_16329c;
            case 0x1632A0u: goto label_1632a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1630D8u;
    // 0x1630d8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1630d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1630dc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1630dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1630e0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1630e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1630e4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1630e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1630e8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1630e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1630ec: 0xc058d10  jal         func_163440
    ctx->pc = 0x1630ECu;
    SET_GPR_U32(ctx, 31, 0x1630F4u);
    ctx->pc = 0x1630F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1630ECu;
            // 0x1630f0: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163440u;
    if (runtime->hasFunction(0x163440u)) {
        auto targetFn = runtime->lookupFunction(0x163440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1630F4u; }
        if (ctx->pc != 0x1630F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163440_0x163440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1630F4u; }
        if (ctx->pc != 0x1630F4u) { return; }
    }
    ctx->pc = 0x1630F4u;
label_1630f4:
    // 0x1630f4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1630f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1630f8: 0x5443000b  bnel        $v0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x1630F8u;
    {
        const bool branch_taken_0x1630f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1630f8) {
            ctx->pc = 0x1630FCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1630F8u;
            // 0x1630fc: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x163128u;
            goto label_163128;
        }
    }
    ctx->pc = 0x163100u;
    // 0x163100: 0xc058d08  jal         func_163420
    ctx->pc = 0x163100u;
    SET_GPR_U32(ctx, 31, 0x163108u);
    ctx->pc = 0x163420u;
    if (runtime->hasFunction(0x163420u)) {
        auto targetFn = runtime->lookupFunction(0x163420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163108u; }
        if (ctx->pc != 0x163108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163420_0x163420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163108u; }
        if (ctx->pc != 0x163108u) { return; }
    }
    ctx->pc = 0x163108u;
label_163108:
    // 0x163108: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x163108u;
    {
        const bool branch_taken_0x163108 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16310Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163108u;
            // 0x16310c: 0x8e040014  lw          $a0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163108) {
            ctx->pc = 0x163124u;
            goto label_163124;
        }
    }
    ctx->pc = 0x163110u;
    // 0x163110: 0x8c420028  lw          $v0, 0x28($v0)
    ctx->pc = 0x163110u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x163114: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x163114u;
    {
        const bool branch_taken_0x163114 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x163114) {
            ctx->pc = 0x163118u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x163114u;
            // 0x163118: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x163128u;
            goto label_163128;
        }
    }
    ctx->pc = 0x16311Cu;
    // 0x16311c: 0x40f809  jalr        $v0
    ctx->pc = 0x16311Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x163124u);
        ctx->pc = 0x163120u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16311Cu;
            // 0x163120: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x163124u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163094u: goto label_163094;
            case 0x1630A8u: goto label_1630a8;
            case 0x1630C4u: goto label_1630c4;
            case 0x1630C8u: goto label_1630c8;
            case 0x1630F4u: goto label_1630f4;
            case 0x163108u: goto label_163108;
            case 0x163124u: goto label_163124;
            case 0x163128u: goto label_163128;
            case 0x163154u: goto label_163154;
            case 0x163168u: goto label_163168;
            case 0x163184u: goto label_163184;
            case 0x163188u: goto label_163188;
            case 0x16318Cu: goto label_16318c;
            case 0x1631D8u: goto label_1631d8;
            case 0x1631E8u: goto label_1631e8;
            case 0x163208u: goto label_163208;
            case 0x16322Cu: goto label_16322c;
            case 0x163248u: goto label_163248;
            case 0x163254u: goto label_163254;
            case 0x163278u: goto label_163278;
            case 0x163280u: goto label_163280;
            case 0x163288u: goto label_163288;
            case 0x163298u: goto label_163298;
            case 0x16329Cu: goto label_16329c;
            case 0x1632A0u: goto label_1632a0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x163124u; }
            if (ctx->pc != 0x163124u) { return; }
        }
        }
    }
    ctx->pc = 0x163124u;
label_163124:
    // 0x163124: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x163124u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_163128:
    // 0x163128: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x163128u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16312c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16312cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x163130: 0x3e00008  jr          $ra
    ctx->pc = 0x163130u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163130u;
            // 0x163134: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163094u: goto label_163094;
            case 0x1630A8u: goto label_1630a8;
            case 0x1630C4u: goto label_1630c4;
            case 0x1630C8u: goto label_1630c8;
            case 0x1630F4u: goto label_1630f4;
            case 0x163108u: goto label_163108;
            case 0x163124u: goto label_163124;
            case 0x163128u: goto label_163128;
            case 0x163154u: goto label_163154;
            case 0x163168u: goto label_163168;
            case 0x163184u: goto label_163184;
            case 0x163188u: goto label_163188;
            case 0x16318Cu: goto label_16318c;
            case 0x1631D8u: goto label_1631d8;
            case 0x1631E8u: goto label_1631e8;
            case 0x163208u: goto label_163208;
            case 0x16322Cu: goto label_16322c;
            case 0x163248u: goto label_163248;
            case 0x163254u: goto label_163254;
            case 0x163278u: goto label_163278;
            case 0x163280u: goto label_163280;
            case 0x163288u: goto label_163288;
            case 0x163298u: goto label_163298;
            case 0x16329Cu: goto label_16329c;
            case 0x1632A0u: goto label_1632a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163138u;
    // 0x163138: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x163138u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16313c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16313cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x163140: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x163140u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163144: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x163144u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x163148: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x163148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x16314c: 0xc058d10  jal         func_163440
    ctx->pc = 0x16314Cu;
    SET_GPR_U32(ctx, 31, 0x163154u);
    ctx->pc = 0x163150u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16314Cu;
            // 0x163150: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163440u;
    if (runtime->hasFunction(0x163440u)) {
        auto targetFn = runtime->lookupFunction(0x163440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163154u; }
        if (ctx->pc != 0x163154u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163440_0x163440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163154u; }
        if (ctx->pc != 0x163154u) { return; }
    }
    ctx->pc = 0x163154u;
label_163154:
    // 0x163154: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x163154u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x163158: 0x1443000c  bne         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x163158u;
    {
        const bool branch_taken_0x163158 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x16315Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163158u;
            // 0x16315c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163158) {
            ctx->pc = 0x16318Cu;
            goto label_16318c;
        }
    }
    ctx->pc = 0x163160u;
    // 0x163160: 0xc058d08  jal         func_163420
    ctx->pc = 0x163160u;
    SET_GPR_U32(ctx, 31, 0x163168u);
    ctx->pc = 0x163420u;
    if (runtime->hasFunction(0x163420u)) {
        auto targetFn = runtime->lookupFunction(0x163420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163168u; }
        if (ctx->pc != 0x163168u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163420_0x163420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163168u; }
        if (ctx->pc != 0x163168u) { return; }
    }
    ctx->pc = 0x163168u;
label_163168:
    // 0x163168: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x163168u;
    {
        const bool branch_taken_0x163168 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16316Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163168u;
            // 0x16316c: 0x8e040014  lw          $a0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163168) {
            ctx->pc = 0x163188u;
            goto label_163188;
        }
    }
    ctx->pc = 0x163170u;
    // 0x163170: 0x8c42002c  lw          $v0, 0x2C($v0)
    ctx->pc = 0x163170u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 44)));
    // 0x163174: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x163174u;
    {
        const bool branch_taken_0x163174 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x163174) {
            ctx->pc = 0x163178u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x163174u;
            // 0x163178: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16318Cu;
            goto label_16318c;
        }
    }
    ctx->pc = 0x16317Cu;
    // 0x16317c: 0x40f809  jalr        $v0
    ctx->pc = 0x16317Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x163184u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x163184u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163094u: goto label_163094;
            case 0x1630A8u: goto label_1630a8;
            case 0x1630C4u: goto label_1630c4;
            case 0x1630C8u: goto label_1630c8;
            case 0x1630F4u: goto label_1630f4;
            case 0x163108u: goto label_163108;
            case 0x163124u: goto label_163124;
            case 0x163128u: goto label_163128;
            case 0x163154u: goto label_163154;
            case 0x163168u: goto label_163168;
            case 0x163184u: goto label_163184;
            case 0x163188u: goto label_163188;
            case 0x16318Cu: goto label_16318c;
            case 0x1631D8u: goto label_1631d8;
            case 0x1631E8u: goto label_1631e8;
            case 0x163208u: goto label_163208;
            case 0x16322Cu: goto label_16322c;
            case 0x163248u: goto label_163248;
            case 0x163254u: goto label_163254;
            case 0x163278u: goto label_163278;
            case 0x163280u: goto label_163280;
            case 0x163288u: goto label_163288;
            case 0x163298u: goto label_163298;
            case 0x16329Cu: goto label_16329c;
            case 0x1632A0u: goto label_1632a0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x163184u; }
            if (ctx->pc != 0x163184u) { return; }
        }
        }
    }
    ctx->pc = 0x163184u;
label_163184:
    // 0x163184: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x163184u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_163188:
    // 0x163188: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x163188u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_16318c:
    // 0x16318c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16318cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163190: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x163190u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163194: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x163194u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x163198: 0x3e00008  jr          $ra
    ctx->pc = 0x163198u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16319Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163198u;
            // 0x16319c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163094u: goto label_163094;
            case 0x1630A8u: goto label_1630a8;
            case 0x1630C4u: goto label_1630c4;
            case 0x1630C8u: goto label_1630c8;
            case 0x1630F4u: goto label_1630f4;
            case 0x163108u: goto label_163108;
            case 0x163124u: goto label_163124;
            case 0x163128u: goto label_163128;
            case 0x163154u: goto label_163154;
            case 0x163168u: goto label_163168;
            case 0x163184u: goto label_163184;
            case 0x163188u: goto label_163188;
            case 0x16318Cu: goto label_16318c;
            case 0x1631D8u: goto label_1631d8;
            case 0x1631E8u: goto label_1631e8;
            case 0x163208u: goto label_163208;
            case 0x16322Cu: goto label_16322c;
            case 0x163248u: goto label_163248;
            case 0x163254u: goto label_163254;
            case 0x163278u: goto label_163278;
            case 0x163280u: goto label_163280;
            case 0x163288u: goto label_163288;
            case 0x163298u: goto label_163298;
            case 0x16329Cu: goto label_16329c;
            case 0x1632A0u: goto label_1632a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1631A0u;
    // 0x1631a0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1631a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1631a4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1631a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1631a8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1631a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1631ac: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1631acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1631b0: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1631b0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1631b4: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1631b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1631b8: 0x261201ec  addiu       $s2, $s0, 0x1EC
    ctx->pc = 0x1631b8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 492));
    // 0x1631bc: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x1631bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x1631c0: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1631c0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1631c4: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x1631c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x1631c8: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x1631c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x1631cc: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1631ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1631d0: 0xc058d08  jal         func_163420
    ctx->pc = 0x1631D0u;
    SET_GPR_U32(ctx, 31, 0x1631D8u);
    ctx->pc = 0x1631D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1631D0u;
            // 0x1631d4: 0xe0a02d  daddu       $s4, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163420u;
    if (runtime->hasFunction(0x163420u)) {
        auto targetFn = runtime->lookupFunction(0x163420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1631D8u; }
        if (ctx->pc != 0x1631D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163420_0x163420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1631D8u; }
        if (ctx->pc != 0x1631D8u) { return; }
    }
    ctx->pc = 0x1631D8u;
label_1631d8:
    // 0x1631d8: 0x50400031  beql        $v0, $zero, . + 4 + (0x31 << 2)
    ctx->pc = 0x1631D8u;
    {
        const bool branch_taken_0x1631d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1631d8) {
            ctx->pc = 0x1631DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1631D8u;
            // 0x1631dc: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1632A0u;
            goto label_1632a0;
        }
    }
    ctx->pc = 0x1631E0u;
    // 0x1631e0: 0xc058b48  jal         func_162D20
    ctx->pc = 0x1631E0u;
    SET_GPR_U32(ctx, 31, 0x1631E8u);
    ctx->pc = 0x162D20u;
    if (runtime->hasFunction(0x162D20u)) {
        auto targetFn = runtime->lookupFunction(0x162D20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1631E8u; }
        if (ctx->pc != 0x1631E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162D20_0x162d20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1631E8u; }
        if (ctx->pc != 0x1631E8u) { return; }
    }
    ctx->pc = 0x1631E8u;
label_1631e8:
    // 0x1631e8: 0x8e150040  lw          $s5, 0x40($s0)
    ctx->pc = 0x1631e8u;
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x1631ec: 0xae510008  sw          $s1, 0x8($s2)
    ctx->pc = 0x1631ecu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 17));
    // 0x1631f0: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1631f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1631f4: 0xae530004  sw          $s3, 0x4($s2)
    ctx->pc = 0x1631f4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 19));
    // 0x1631f8: 0x27a50004  addiu       $a1, $sp, 0x4
    ctx->pc = 0x1631f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x1631fc: 0xae540010  sw          $s4, 0x10($s2)
    ctx->pc = 0x1631fcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 20));
    // 0x163200: 0xc058b7a  jal         func_162DE8
    ctx->pc = 0x163200u;
    SET_GPR_U32(ctx, 31, 0x163208u);
    ctx->pc = 0x163204u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163200u;
            // 0x163204: 0x27a60008  addiu       $a2, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162DE8u;
    if (runtime->hasFunction(0x162DE8u)) {
        auto targetFn = runtime->lookupFunction(0x162DE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163208u; }
        if (ctx->pc != 0x163208u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162DE8_0x162de8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163208u; }
        if (ctx->pc != 0x163208u) { return; }
    }
    ctx->pc = 0x163208u;
label_163208:
    // 0x163208: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x163208u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x16320c: 0x222102a  slt         $v0, $s1, $v0
    ctx->pc = 0x16320cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x163210: 0x14400019  bnez        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x163210u;
    {
        const bool branch_taken_0x163210 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x163214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163210u;
            // 0x163214: 0x24840418  addiu       $a0, $a0, 0x418 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1048));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163210) {
            ctx->pc = 0x163278u;
            goto label_163278;
        }
    }
    ctx->pc = 0x163218u;
    // 0x163218: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x163218u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16321c: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x16321cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x163220: 0x8fa60008  lw          $a2, 0x8($sp)
    ctx->pc = 0x163220u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163224: 0xc04fe2a  jal         func_13F8A8
    ctx->pc = 0x163224u;
    SET_GPR_U32(ctx, 31, 0x16322Cu);
    ctx->pc = 0x163228u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163224u;
            // 0x163228: 0x2642021  addu        $a0, $s3, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F8A8u;
    if (runtime->hasFunction(0x13F8A8u)) {
        auto targetFn = runtime->lookupFunction(0x13F8A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16322Cu; }
        if (ctx->pc != 0x16322Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F8A8_0x13f8a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16322Cu; }
        if (ctx->pc != 0x16322Cu) { return; }
    }
    ctx->pc = 0x16322Cu;
label_16322c:
    // 0x16322c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x16322cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163230: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x163230u;
    {
        const bool branch_taken_0x163230 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x163234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163230u;
            // 0x163234: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163230) {
            ctx->pc = 0x163248u;
            goto label_163248;
        }
    }
    ctx->pc = 0x163238u;
    // 0x163238: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x163238u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x16323c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x16323Cu;
    {
        const bool branch_taken_0x16323c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x163240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16323Cu;
            // 0x163240: 0x24840448  addiu       $a0, $a0, 0x448 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1096));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16323c) {
            ctx->pc = 0x163278u;
            goto label_163278;
        }
    }
    ctx->pc = 0x163244u;
    // 0x163244: 0x0  nop
    ctx->pc = 0x163244u;
    // NOP
label_163248:
    // 0x163248: 0xae51000c  sw          $s1, 0xC($s2)
    ctx->pc = 0x163248u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 17));
    // 0x16324c: 0xc058b94  jal         func_162E50
    ctx->pc = 0x16324Cu;
    SET_GPR_U32(ctx, 31, 0x163254u);
    ctx->pc = 0x163250u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16324Cu;
            // 0x163250: 0x8fa50000  lw          $a1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162E50u;
    if (runtime->hasFunction(0x162E50u)) {
        auto targetFn = runtime->lookupFunction(0x162E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163254u; }
        if (ctx->pc != 0x163254u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162E50_0x162e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163254u; }
        if (ctx->pc != 0x163254u) { return; }
    }
    ctx->pc = 0x163254u;
label_163254:
    // 0x163254: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x163254u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163258: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x163258u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16325c: 0x268500c0  addiu       $a1, $s4, 0xC0
    ctx->pc = 0x16325cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), 192));
    // 0x163260: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x163260u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163264: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x163264u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163268: 0x16000007  bnez        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x163268u;
    {
        const bool branch_taken_0x163268 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x16326Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163268u;
            // 0x16326c: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163268) {
            ctx->pc = 0x163288u;
            goto label_163288;
        }
    }
    ctx->pc = 0x163270u;
    // 0x163270: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x163270u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x163274: 0x24840470  addiu       $a0, $a0, 0x470
    ctx->pc = 0x163274u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1136));
label_163278:
    // 0x163278: 0xc058dd4  jal         func_163750
    ctx->pc = 0x163278u;
    SET_GPR_U32(ctx, 31, 0x163280u);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163280u; }
        if (ctx->pc != 0x163280u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163280u; }
        if (ctx->pc != 0x163280u) { return; }
    }
    ctx->pc = 0x163280u;
label_163280:
    // 0x163280: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x163280u;
    {
        const bool branch_taken_0x163280 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x163284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163280u;
            // 0x163284: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163280) {
            ctx->pc = 0x16329Cu;
            goto label_16329c;
        }
    }
    ctx->pc = 0x163288u;
label_163288:
    // 0x163288: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x163288u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16328c: 0xae500014  sw          $s0, 0x14($s2)
    ctx->pc = 0x16328cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 16));
    // 0x163290: 0xc05a7fc  jal         func_169FF0
    ctx->pc = 0x163290u;
    SET_GPR_U32(ctx, 31, 0x163298u);
    ctx->pc = 0x163294u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163290u;
            // 0x163294: 0xae420000  sw          $v0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169FF0u;
    if (runtime->hasFunction(0x169FF0u)) {
        auto targetFn = runtime->lookupFunction(0x169FF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163298u; }
        if (ctx->pc != 0x163298u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169FF0_0x169ff0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163298u; }
        if (ctx->pc != 0x163298u) { return; }
    }
    ctx->pc = 0x163298u;
label_163298:
    // 0x163298: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x163298u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_16329c:
    // 0x16329c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16329cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1632a0:
    // 0x1632a0: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x1632a0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1632a4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1632a4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1632a8: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x1632a8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1632ac: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x1632acu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1632b0: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x1632b0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1632b4: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1632b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1632b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1632B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1632BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1632B8u;
            // 0x1632bc: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163094u: goto label_163094;
            case 0x1630A8u: goto label_1630a8;
            case 0x1630C4u: goto label_1630c4;
            case 0x1630C8u: goto label_1630c8;
            case 0x1630F4u: goto label_1630f4;
            case 0x163108u: goto label_163108;
            case 0x163124u: goto label_163124;
            case 0x163128u: goto label_163128;
            case 0x163154u: goto label_163154;
            case 0x163168u: goto label_163168;
            case 0x163184u: goto label_163184;
            case 0x163188u: goto label_163188;
            case 0x16318Cu: goto label_16318c;
            case 0x1631D8u: goto label_1631d8;
            case 0x1631E8u: goto label_1631e8;
            case 0x163208u: goto label_163208;
            case 0x16322Cu: goto label_16322c;
            case 0x163248u: goto label_163248;
            case 0x163254u: goto label_163254;
            case 0x163278u: goto label_163278;
            case 0x163280u: goto label_163280;
            case 0x163288u: goto label_163288;
            case 0x163298u: goto label_163298;
            case 0x16329Cu: goto label_16329c;
            case 0x1632A0u: goto label_1632a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1632C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
