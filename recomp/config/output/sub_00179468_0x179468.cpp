#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179468
// Address: 0x179468 - 0x179538
void sub_00179468_0x179468(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179468_0x179468");
#endif

    switch (ctx->pc) {
        case 0x1794a4u: goto label_1794a4;
        case 0x1794d8u: goto label_1794d8;
        case 0x1794f0u: goto label_1794f0;
        case 0x179500u: goto label_179500;
        case 0x179518u: goto label_179518;
        default: break;
    }

    ctx->pc = 0x179468u;

    // 0x179468: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179468u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17946c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x17946cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179470: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179470u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179474: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x179474u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x179478: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179478u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17947c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17947cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179480: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x179480u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x179484: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x179484u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179488: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x179488u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17948c: 0x8e23000c  lw          $v1, 0xC($s1)
    ctx->pc = 0x17948cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x179490: 0x2863006e  slti        $v1, $v1, 0x6E
    ctx->pc = 0x179490u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)110) ? 1 : 0);
    // 0x179494: 0x14600022  bnez        $v1, . + 4 + (0x22 << 2)
    ctx->pc = 0x179494u;
    {
        const bool branch_taken_0x179494 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x179498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179494u;
            // 0x179498: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179494) {
            ctx->pc = 0x179520u;
            goto label_179520;
        }
    }
    ctx->pc = 0x17949Cu;
    // 0x17949c: 0xc05e976  jal         func_17A5D8
    ctx->pc = 0x17949Cu;
    SET_GPR_U32(ctx, 31, 0x1794A4u);
    ctx->pc = 0x17A5D8u;
    if (runtime->hasFunction(0x17A5D8u)) {
        auto targetFn = runtime->lookupFunction(0x17A5D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1794A4u; }
        if (ctx->pc != 0x1794A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A5D8_0x17a5d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1794A4u; }
        if (ctx->pc != 0x1794A4u) { return; }
    }
    ctx->pc = 0x1794A4u;
label_1794a4:
    // 0x1794a4: 0x240600e0  addiu       $a2, $zero, 0xE0
    ctx->pc = 0x1794a4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 224));
    // 0x1794a8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1794a8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1794ac: 0x240200c0  addiu       $v0, $zero, 0xC0
    ctx->pc = 0x1794acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x1794b0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1794b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1794b4: 0x10620006  beq         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1794B4u;
    {
        const bool branch_taken_0x1794b4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1794B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1794B4u;
            // 0x1794b8: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1794b4) {
            ctx->pc = 0x1794D0u;
            goto label_1794d0;
        }
    }
    ctx->pc = 0x1794BCu;
    // 0x1794bc: 0x1066000e  beq         $v1, $a2, . + 4 + (0xE << 2)
    ctx->pc = 0x1794BCu;
    {
        const bool branch_taken_0x1794bc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 6));
        ctx->pc = 0x1794C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1794BCu;
            // 0x1794c0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1794bc) {
            ctx->pc = 0x1794F8u;
            goto label_1794f8;
        }
    }
    ctx->pc = 0x1794C4u;
    // 0x1794c4: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1794C4u;
    {
        const bool branch_taken_0x1794c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1794C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1794C4u;
            // 0x1794c8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1794c4) {
            ctx->pc = 0x179524u;
            goto label_179524;
        }
    }
    ctx->pc = 0x1794CCu;
    // 0x1794cc: 0x0  nop
    ctx->pc = 0x1794ccu;
    // NOP
label_1794d0:
    // 0x1794d0: 0xc05e756  jal         func_179D58
    ctx->pc = 0x1794D0u;
    SET_GPR_U32(ctx, 31, 0x1794D8u);
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1794D8u; }
        if (ctx->pc != 0x1794D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1794D8u; }
        if (ctx->pc != 0x1794D8u) { return; }
    }
    ctx->pc = 0x1794D8u;
label_1794d8:
    // 0x1794d8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1794d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1794dc: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1794dcu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1794e0: 0x1060000f  beqz        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x1794E0u;
    {
        const bool branch_taken_0x1794e0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1794E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1794E0u;
            // 0x1794e4: 0x60282d  daddu       $a1, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1794e0) {
            ctx->pc = 0x179520u;
            goto label_179520;
        }
    }
    ctx->pc = 0x1794E8u;
    // 0x1794e8: 0xc05e956  jal         func_17A558
    ctx->pc = 0x1794E8u;
    SET_GPR_U32(ctx, 31, 0x1794F0u);
    ctx->pc = 0x17A558u;
    if (runtime->hasFunction(0x17A558u)) {
        auto targetFn = runtime->lookupFunction(0x17A558u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1794F0u; }
        if (ctx->pc != 0x1794F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A558_0x17a558(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1794F0u; }
        if (ctx->pc != 0x1794F0u) { return; }
    }
    ctx->pc = 0x1794F0u;
label_1794f0:
    // 0x1794f0: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1794F0u;
    {
        const bool branch_taken_0x1794f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1794F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1794F0u;
            // 0x1794f4: 0xae420000  sw          $v0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1794f0) {
            ctx->pc = 0x17951Cu;
            goto label_17951c;
        }
    }
    ctx->pc = 0x1794F8u;
label_1794f8:
    // 0x1794f8: 0xc05e756  jal         func_179D58
    ctx->pc = 0x1794F8u;
    SET_GPR_U32(ctx, 31, 0x179500u);
    ctx->pc = 0x1794FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1794F8u;
            // 0x1794fc: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179500u; }
        if (ctx->pc != 0x179500u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179500u; }
        if (ctx->pc != 0x179500u) { return; }
    }
    ctx->pc = 0x179500u;
label_179500:
    // 0x179500: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x179500u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179504: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x179504u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179508: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x179508u;
    {
        const bool branch_taken_0x179508 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x17950Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179508u;
            // 0x17950c: 0x60282d  daddu       $a1, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179508) {
            ctx->pc = 0x179520u;
            goto label_179520;
        }
    }
    ctx->pc = 0x179510u;
    // 0x179510: 0xc05e966  jal         func_17A598
    ctx->pc = 0x179510u;
    SET_GPR_U32(ctx, 31, 0x179518u);
    ctx->pc = 0x17A598u;
    if (runtime->hasFunction(0x17A598u)) {
        auto targetFn = runtime->lookupFunction(0x17A598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179518u; }
        if (ctx->pc != 0x179518u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A598_0x17a598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179518u; }
        if (ctx->pc != 0x179518u) { return; }
    }
    ctx->pc = 0x179518u;
label_179518:
    // 0x179518: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x179518u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
label_17951c:
    // 0x17951c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17951cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_179520:
    // 0x179520: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179520u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_179524:
    // 0x179524: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179524u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179528: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x179528u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17952c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17952cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x179530: 0x3e00008  jr          $ra
    ctx->pc = 0x179530u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179530u;
            // 0x179534: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1794A4u: goto label_1794a4;
            case 0x1794D0u: goto label_1794d0;
            case 0x1794D8u: goto label_1794d8;
            case 0x1794F0u: goto label_1794f0;
            case 0x1794F8u: goto label_1794f8;
            case 0x179500u: goto label_179500;
            case 0x179518u: goto label_179518;
            case 0x17951Cu: goto label_17951c;
            case 0x179520u: goto label_179520;
            case 0x179524u: goto label_179524;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179538u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
