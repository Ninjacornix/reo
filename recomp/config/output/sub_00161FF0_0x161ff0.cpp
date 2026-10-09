#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161FF0
// Address: 0x161ff0 - 0x162090
void sub_00161FF0_0x161ff0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161FF0_0x161ff0");
#endif

    switch (ctx->pc) {
        case 0x162010u: goto label_162010;
        case 0x162024u: goto label_162024;
        case 0x162048u: goto label_162048;
        case 0x162058u: goto label_162058;
        case 0x16206cu: goto label_16206c;
        case 0x162078u: goto label_162078;
        default: break;
    }

    ctx->pc = 0x161ff0u;

    // 0x161ff0: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x161ff0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x161ff4: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x161ff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x161ff8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x161ff8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ffc: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x161ffcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x162000: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x162000u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x162004: 0xffbf00a8  sd          $ra, 0xA8($sp)
    ctx->pc = 0x162004u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 31));
    // 0x162008: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x162008u;
    SET_GPR_U32(ctx, 31, 0x162010u);
    ctx->pc = 0x16200Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162008u;
            // 0x16200c: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162010u; }
        if (ctx->pc != 0x162010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162010u; }
        if (ctx->pc != 0x162010u) { return; }
    }
    ctx->pc = 0x162010u;
label_162010:
    // 0x162010: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x162010u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x162014: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x162014u;
    {
        const bool branch_taken_0x162014 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x162018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162014u;
            // 0x162018: 0x2484ff68  addiu       $a0, $a0, -0x98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967144));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162014) {
            ctx->pc = 0x162030u;
            goto label_162030;
        }
    }
    ctx->pc = 0x16201Cu;
    // 0x16201c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x16201Cu;
    SET_GPR_U32(ctx, 31, 0x162024u);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162024u; }
        if (ctx->pc != 0x162024u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162024u; }
        if (ctx->pc != 0x162024u) { return; }
    }
    ctx->pc = 0x162024u;
label_162024:
    // 0x162024: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x162024u;
    {
        const bool branch_taken_0x162024 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x162028u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162024u;
            // 0x162028: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162024) {
            ctx->pc = 0x16207Cu;
            goto label_16207c;
        }
    }
    ctx->pc = 0x16202Cu;
    // 0x16202c: 0x0  nop
    ctx->pc = 0x16202cu;
    // NOP
label_162030:
    // 0x162030: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x162030u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x162034: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x162034u;
    {
        const bool branch_taken_0x162034 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x162034) {
            ctx->pc = 0x162050u;
            goto label_162050;
        }
    }
    ctx->pc = 0x16203Cu;
    // 0x16203c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x16203cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x162040: 0xc058dd4  jal         func_163750
    ctx->pc = 0x162040u;
    SET_GPR_U32(ctx, 31, 0x162048u);
    ctx->pc = 0x162044u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162040u;
            // 0x162044: 0x2484ff98  addiu       $a0, $a0, -0x68 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162048u; }
        if (ctx->pc != 0x162048u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162048u; }
        if (ctx->pc != 0x162048u) { return; }
    }
    ctx->pc = 0x162048u;
label_162048:
    // 0x162048: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x162048u;
    {
        const bool branch_taken_0x162048 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16204Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162048u;
            // 0x16204c: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162048) {
            ctx->pc = 0x16207Cu;
            goto label_16207c;
        }
    }
    ctx->pc = 0x162050u;
label_162050:
    // 0x162050: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x162050u;
    SET_GPR_U32(ctx, 31, 0x162058u);
    ctx->pc = 0x162054u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162050u;
            // 0x162054: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162058u; }
        if (ctx->pc != 0x162058u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162058u; }
        if (ctx->pc != 0x162058u) { return; }
    }
    ctx->pc = 0x162058u;
label_162058:
    // 0x162058: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x162058u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16205c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x16205cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162060: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x162060u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162064: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x162064u;
    SET_GPR_U32(ctx, 31, 0x16206Cu);
    ctx->pc = 0x162068u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162064u;
            // 0x162068: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16206Cu; }
        if (ctx->pc != 0x16206Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16206Cu; }
        if (ctx->pc != 0x16206Cu) { return; }
    }
    ctx->pc = 0x16206Cu;
label_16206c:
    // 0x16206c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x16206cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162070: 0xc05f26a  jal         func_17C9A8
    ctx->pc = 0x162070u;
    SET_GPR_U32(ctx, 31, 0x162078u);
    ctx->pc = 0x162074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162070u;
            // 0x162074: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C9A8u;
    if (runtime->hasFunction(0x17C9A8u)) {
        auto targetFn = runtime->lookupFunction(0x17C9A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162078u; }
        if (ctx->pc != 0x162078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C9A8_0x17c9a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162078u; }
        if (ctx->pc != 0x162078u) { return; }
    }
    ctx->pc = 0x162078u;
label_162078:
    // 0x162078: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x162078u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_16207c:
    // 0x16207c: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x16207cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x162080: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x162080u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x162084: 0xdfbf00a8  ld          $ra, 0xA8($sp)
    ctx->pc = 0x162084u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x162088: 0x3e00008  jr          $ra
    ctx->pc = 0x162088u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16208Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162088u;
            // 0x16208c: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162010u: goto label_162010;
            case 0x162024u: goto label_162024;
            case 0x162030u: goto label_162030;
            case 0x162048u: goto label_162048;
            case 0x162050u: goto label_162050;
            case 0x162058u: goto label_162058;
            case 0x16206Cu: goto label_16206c;
            case 0x162078u: goto label_162078;
            case 0x16207Cu: goto label_16207c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162090u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
