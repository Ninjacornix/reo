#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011F4F8
// Address: 0x11f4f8 - 0x11f5a0
void sub_0011F4F8_0x11f4f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011F4F8_0x11f4f8");
#endif

    switch (ctx->pc) {
        case 0x11f51cu: goto label_11f51c;
        case 0x11f548u: goto label_11f548;
        case 0x11f560u: goto label_11f560;
        case 0x11f584u: goto label_11f584;
        default: break;
    }

    ctx->pc = 0x11f4f8u;

    // 0x11f4f8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x11f4f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11f4fc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11f4fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11f500: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x11f500u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f504: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11f504u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11f508: 0x101202  srl         $v0, $s0, 8
    ctx->pc = 0x11f508u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), 8));
    // 0x11f50c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11f50cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11f510: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x11f510u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11f514: 0xc047598  jal         func_11D660
    ctx->pc = 0x11F514u;
    SET_GPR_U32(ctx, 31, 0x11F51Cu);
    ctx->pc = 0x11F518u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F514u;
            // 0x11f518: 0x28900  sll         $s1, $v0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F51Cu; }
        if (ctx->pc != 0x11F51Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F51Cu; }
        if (ctx->pc != 0x11F51Cu) { return; }
    }
    ctx->pc = 0x11F51Cu;
label_11f51c:
    // 0x11f51c: 0x6000006  bltz        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x11F51Cu;
    {
        const bool branch_taken_0x11f51c = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x11F520u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F51Cu;
            // 0x11f520: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f51c) {
            ctx->pc = 0x11F538u;
            goto label_11f538;
        }
    }
    ctx->pc = 0x11F524u;
    // 0x11f524: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x11f524u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x11f528: 0x2021026  xor         $v0, $s0, $v0
    ctx->pc = 0x11f528u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) ^ GPR_U64(ctx, 2));
    // 0x11f52c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x11f52cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x11f530: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x11F530u;
    {
        const bool branch_taken_0x11f530 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11f530) {
            ctx->pc = 0x11F554u;
            goto label_11f554;
        }
    }
    ctx->pc = 0x11F538u;
label_11f538:
    // 0x11f538: 0x12400003  beqz        $s2, . + 4 + (0x3 << 2)
    ctx->pc = 0x11F538u;
    {
        const bool branch_taken_0x11f538 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x11f538) {
            ctx->pc = 0x11F548u;
            goto label_11f548;
        }
    }
    ctx->pc = 0x11F540u;
    // 0x11f540: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11F540u;
    SET_GPR_U32(ctx, 31, 0x11F548u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F548u; }
        if (ctx->pc != 0x11F548u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F548u; }
        if (ctx->pc != 0x11F548u) { return; }
    }
    ctx->pc = 0x11F548u;
label_11f548:
    // 0x11f548: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11f548u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11f54c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x11F54Cu;
    {
        const bool branch_taken_0x11f54c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F54Cu;
            // 0x11f550: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f54c) {
            ctx->pc = 0x11F588u;
            goto label_11f588;
        }
    }
    ctx->pc = 0x11F554u;
label_11f554:
    // 0x11f554: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x11f554u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x11f558: 0xc047a72  jal         func_11E9C8
    ctx->pc = 0x11F558u;
    SET_GPR_U32(ctx, 31, 0x11F560u);
    ctx->pc = 0x11E9C8u;
    if (runtime->hasFunction(0x11E9C8u)) {
        auto targetFn = runtime->lookupFunction(0x11E9C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F560u; }
        if (ctx->pc != 0x11F560u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E9C8_0x11e9c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F560u; }
        if (ctx->pc != 0x11F560u) { return; }
    }
    ctx->pc = 0x11F560u;
label_11f560:
    // 0x11f560: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x11f560u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x11f564: 0x8c621d00  lw          $v0, 0x1D00($v1)
    ctx->pc = 0x11f564u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7424)));
    // 0x11f568: 0xac711d00  sw          $s1, 0x1D00($v1)
    ctx->pc = 0x11f568u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 7424), GPR_U32(ctx, 17));
    // 0x11f56c: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x11f56cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x11f570: 0xae200004  sw          $zero, 0x4($s1)
    ctx->pc = 0x11f570u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
    // 0x11f574: 0x12400004  beqz        $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x11F574u;
    {
        const bool branch_taken_0x11f574 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F574u;
            // 0x11f578: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f574) {
            ctx->pc = 0x11F588u;
            goto label_11f588;
        }
    }
    ctx->pc = 0x11F57Cu;
    // 0x11f57c: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11F57Cu;
    SET_GPR_U32(ctx, 31, 0x11F584u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F584u; }
        if (ctx->pc != 0x11F584u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F584u; }
        if (ctx->pc != 0x11F584u) { return; }
    }
    ctx->pc = 0x11F584u;
label_11f584:
    // 0x11f584: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11f584u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_11f588:
    // 0x11f588: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11f588u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11f58c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11f58cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11f590: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11f590u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11f594: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11f594u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f598: 0x3e00008  jr          $ra
    ctx->pc = 0x11F598u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F59Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F598u;
            // 0x11f59c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F51Cu: goto label_11f51c;
            case 0x11F538u: goto label_11f538;
            case 0x11F548u: goto label_11f548;
            case 0x11F554u: goto label_11f554;
            case 0x11F560u: goto label_11f560;
            case 0x11F584u: goto label_11f584;
            case 0x11F588u: goto label_11f588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F5A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
