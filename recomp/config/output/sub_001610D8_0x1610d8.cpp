#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001610D8
// Address: 0x1610d8 - 0x161198
void sub_001610D8_0x1610d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001610D8_0x1610d8");
#endif

    switch (ctx->pc) {
        case 0x161108u: goto label_161108;
        case 0x16111cu: goto label_16111c;
        case 0x16113cu: goto label_16113c;
        case 0x161150u: goto label_161150;
        case 0x161164u: goto label_161164;
        case 0x161178u: goto label_161178;
        default: break;
    }

    ctx->pc = 0x1610d8u;

    // 0x1610d8: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x1610d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x1610dc: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x1610dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x1610e0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1610e0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1610e4: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x1610e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x1610e8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1610e8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1610ec: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x1610ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x1610f0: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x1610f0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1610f4: 0xffb400b0  sd          $s4, 0xB0($sp)
    ctx->pc = 0x1610f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 20));
    // 0x1610f8: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x1610f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x1610fc: 0xffbf00b8  sd          $ra, 0xB8($sp)
    ctx->pc = 0x1610fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 184), GPR_U64(ctx, 31));
    // 0x161100: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x161100u;
    SET_GPR_U32(ctx, 31, 0x161108u);
    ctx->pc = 0x161104u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161100u;
            // 0x161104: 0xe0a02d  daddu       $s4, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161108u; }
        if (ctx->pc != 0x161108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161108u; }
        if (ctx->pc != 0x161108u) { return; }
    }
    ctx->pc = 0x161108u;
label_161108:
    // 0x161108: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161108u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x16110c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16110Cu;
    {
        const bool branch_taken_0x16110c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16110Cu;
            // 0x161110: 0x2484fa18  addiu       $a0, $a0, -0x5E8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965784));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16110c) {
            ctx->pc = 0x161128u;
            goto label_161128;
        }
    }
    ctx->pc = 0x161114u;
    // 0x161114: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161114u;
    SET_GPR_U32(ctx, 31, 0x16111Cu);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16111Cu; }
        if (ctx->pc != 0x16111Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16111Cu; }
        if (ctx->pc != 0x16111Cu) { return; }
    }
    ctx->pc = 0x16111Cu;
label_16111c:
    // 0x16111c: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x16111Cu;
    {
        const bool branch_taken_0x16111c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161120u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16111Cu;
            // 0x161120: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16111c) {
            ctx->pc = 0x16117Cu;
            goto label_16117c;
        }
    }
    ctx->pc = 0x161124u;
    // 0x161124: 0x0  nop
    ctx->pc = 0x161124u;
    // NOP
label_161128:
    // 0x161128: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x161128u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x16112c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16112Cu;
    {
        const bool branch_taken_0x16112c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161130u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16112Cu;
            // 0x161130: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16112c) {
            ctx->pc = 0x161148u;
            goto label_161148;
        }
    }
    ctx->pc = 0x161134u;
    // 0x161134: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161134u;
    SET_GPR_U32(ctx, 31, 0x16113Cu);
    ctx->pc = 0x161138u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161134u;
            // 0x161138: 0x2484fa50  addiu       $a0, $a0, -0x5B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965840));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16113Cu; }
        if (ctx->pc != 0x16113Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16113Cu; }
        if (ctx->pc != 0x16113Cu) { return; }
    }
    ctx->pc = 0x16113Cu;
label_16113c:
    // 0x16113c: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x16113Cu;
    {
        const bool branch_taken_0x16113c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16113Cu;
            // 0x161140: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16113c) {
            ctx->pc = 0x16117Cu;
            goto label_16117c;
        }
    }
    ctx->pc = 0x161144u;
    // 0x161144: 0x0  nop
    ctx->pc = 0x161144u;
    // NOP
label_161148:
    // 0x161148: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161148u;
    SET_GPR_U32(ctx, 31, 0x161150u);
    ctx->pc = 0x16114Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161148u;
            // 0x16114c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161150u; }
        if (ctx->pc != 0x161150u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161150u; }
        if (ctx->pc != 0x161150u) { return; }
    }
    ctx->pc = 0x161150u;
label_161150:
    // 0x161150: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x161150u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161154: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x161154u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161158: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x161158u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16115c: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x16115Cu;
    SET_GPR_U32(ctx, 31, 0x161164u);
    ctx->pc = 0x161160u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16115Cu;
            // 0x161160: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161164u; }
        if (ctx->pc != 0x161164u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161164u; }
        if (ctx->pc != 0x161164u) { return; }
    }
    ctx->pc = 0x161164u;
label_161164:
    // 0x161164: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x161164u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161168: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161168u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16116c: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x16116cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161170: 0xc05efb6  jal         func_17BED8
    ctx->pc = 0x161170u;
    SET_GPR_U32(ctx, 31, 0x161178u);
    ctx->pc = 0x161174u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161170u;
            // 0x161174: 0x280382d  daddu       $a3, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17BED8u;
    if (runtime->hasFunction(0x17BED8u)) {
        auto targetFn = runtime->lookupFunction(0x17BED8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161178u; }
        if (ctx->pc != 0x161178u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017BED8_0x17bed8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161178u; }
        if (ctx->pc != 0x161178u) { return; }
    }
    ctx->pc = 0x161178u;
label_161178:
    // 0x161178: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x161178u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_16117c:
    // 0x16117c: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x16117cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x161180: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x161180u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x161184: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x161184u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x161188: 0xdfb400b0  ld          $s4, 0xB0($sp)
    ctx->pc = 0x161188u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x16118c: 0xdfbf00b8  ld          $ra, 0xB8($sp)
    ctx->pc = 0x16118cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x161190: 0x3e00008  jr          $ra
    ctx->pc = 0x161190u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161194u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161190u;
            // 0x161194: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161108u: goto label_161108;
            case 0x16111Cu: goto label_16111c;
            case 0x161128u: goto label_161128;
            case 0x16113Cu: goto label_16113c;
            case 0x161148u: goto label_161148;
            case 0x161150u: goto label_161150;
            case 0x161164u: goto label_161164;
            case 0x161178u: goto label_161178;
            case 0x16117Cu: goto label_16117c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161198u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
