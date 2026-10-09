#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F510
// Address: 0x15f510 - 0x15f5ac
void sub_0015F510_0x15f510(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F510_0x15f510");
#endif

    switch (ctx->pc) {
        case 0x15f534u: goto label_15f534;
        case 0x15f568u: goto label_15f568;
        case 0x15f57cu: goto label_15f57c;
        case 0x15f58cu: goto label_15f58c;
        default: break;
    }

    ctx->pc = 0x15f510u;

    // 0x15f510: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15f510u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15f514: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f514u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f518: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15f518u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f51c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15f51cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15f520: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x15f520u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f524: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15f524u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15f528: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x15f528u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x15f52c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15F52Cu;
    SET_GPR_U32(ctx, 31, 0x15F534u);
    ctx->pc = 0x15F530u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F52Cu;
            // 0x15f530: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F534u; }
        if (ctx->pc != 0x15F534u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F534u; }
        if (ctx->pc != 0x15F534u) { return; }
    }
    ctx->pc = 0x15F534u;
label_15f534:
    // 0x15f534: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x15F534u;
    {
        const bool branch_taken_0x15f534 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15F538u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F534u;
            // 0x15f538: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f534) {
            ctx->pc = 0x15F560u;
            goto label_15f560;
        }
    }
    ctx->pc = 0x15F53Cu;
    // 0x15f53c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15f53cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15f540: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f540u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f544: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f544u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f548: 0x2484f228  addiu       $a0, $a0, -0xDD8
    ctx->pc = 0x15f548u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963752));
    // 0x15f54c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15f54cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f550: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15f550u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15f554: 0x8058dd4  j           func_163750
    ctx->pc = 0x15F554u;
    ctx->pc = 0x15F558u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F554u;
            // 0x15f558: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F55Cu;
    // 0x15f55c: 0x0  nop
    ctx->pc = 0x15f55cu;
    // NOP
label_15f560:
    // 0x15f560: 0xc0581f6  jal         func_1607D8
    ctx->pc = 0x15F560u;
    SET_GPR_U32(ctx, 31, 0x15F568u);
    ctx->pc = 0x1607D8u;
    if (runtime->hasFunction(0x1607D8u)) {
        auto targetFn = runtime->lookupFunction(0x1607D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F568u; }
        if (ctx->pc != 0x15F568u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001607D8_0x1607d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F568u; }
        if (ctx->pc != 0x15F568u) { return; }
    }
    ctx->pc = 0x15F568u;
label_15f568:
    // 0x15f568: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x15f568u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f56c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x15f56cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15f570: 0x8c43003c  lw          $v1, 0x3C($v0)
    ctx->pc = 0x15f570u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 60)));
    // 0x15f574: 0x60f809  jalr        $v1
    ctx->pc = 0x15F574u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x15F57Cu);
        ctx->pc = 0x15F578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F574u;
            // 0x15f578: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15F57Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F534u: goto label_15f534;
            case 0x15F560u: goto label_15f560;
            case 0x15F568u: goto label_15f568;
            case 0x15F57Cu: goto label_15f57c;
            case 0x15F58Cu: goto label_15f58c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15F57Cu; }
            if (ctx->pc != 0x15F57Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15F57Cu;
label_15f57c:
    // 0x15f57c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f57cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f580: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x15f580u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f584: 0xc057dc6  jal         func_15F718
    ctx->pc = 0x15F584u;
    SET_GPR_U32(ctx, 31, 0x15F58Cu);
    ctx->pc = 0x15F588u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F584u;
            // 0x15f588: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F718u;
    if (runtime->hasFunction(0x15F718u)) {
        auto targetFn = runtime->lookupFunction(0x15F718u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F58Cu; }
        if (ctx->pc != 0x15F58Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F718_0x15f718(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F58Cu; }
        if (ctx->pc != 0x15F58Cu) { return; }
    }
    ctx->pc = 0x15F58Cu;
label_15f58c:
    // 0x15f58c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15f58cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15f590: 0xae020118  sw          $v0, 0x118($s0)
    ctx->pc = 0x15f590u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 280), GPR_U32(ctx, 2));
    // 0x15f594: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f594u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f598: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f598u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f59c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15f59cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f5a0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15f5a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15f5a4: 0x3e00008  jr          $ra
    ctx->pc = 0x15F5A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15F5A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F5A4u;
            // 0x15f5a8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F534u: goto label_15f534;
            case 0x15F560u: goto label_15f560;
            case 0x15F568u: goto label_15f568;
            case 0x15F57Cu: goto label_15f57c;
            case 0x15F58Cu: goto label_15f58c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15F5ACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
