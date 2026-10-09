#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161198
// Address: 0x161198 - 0x161240
void sub_00161198_0x161198(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161198_0x161198");
#endif

    switch (ctx->pc) {
        case 0x1611c0u: goto label_1611c0;
        case 0x1611d4u: goto label_1611d4;
        case 0x1611f0u: goto label_1611f0;
        case 0x161200u: goto label_161200;
        case 0x161214u: goto label_161214;
        case 0x161224u: goto label_161224;
        default: break;
    }

    ctx->pc = 0x161198u;

    // 0x161198: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x161198u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x16119c: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x16119cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x1611a0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1611a0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1611a4: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x1611a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x1611a8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1611a8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1611ac: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x1611acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x1611b0: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x1611b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x1611b4: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x1611b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x1611b8: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1611B8u;
    SET_GPR_U32(ctx, 31, 0x1611C0u);
    ctx->pc = 0x1611BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1611B8u;
            // 0x1611bc: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1611C0u; }
        if (ctx->pc != 0x1611C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1611C0u; }
        if (ctx->pc != 0x1611C0u) { return; }
    }
    ctx->pc = 0x1611C0u;
label_1611c0:
    // 0x1611c0: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x1611C0u;
    {
        const bool branch_taken_0x1611c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1611c0) {
            ctx->pc = 0x1611C4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1611C0u;
            // 0x1611c4: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1611E0u;
            goto label_1611e0;
        }
    }
    ctx->pc = 0x1611C8u;
    // 0x1611c8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1611c8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1611cc: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1611CCu;
    SET_GPR_U32(ctx, 31, 0x1611D4u);
    ctx->pc = 0x1611D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1611CCu;
            // 0x1611d0: 0x2484fa88  addiu       $a0, $a0, -0x578 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965896));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1611D4u; }
        if (ctx->pc != 0x1611D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1611D4u; }
        if (ctx->pc != 0x1611D4u) { return; }
    }
    ctx->pc = 0x1611D4u;
label_1611d4:
    // 0x1611d4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1611D4u;
    {
        const bool branch_taken_0x1611d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1611D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1611D4u;
            // 0x1611d8: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1611d4) {
            ctx->pc = 0x161228u;
            goto label_161228;
        }
    }
    ctx->pc = 0x1611DCu;
    // 0x1611dc: 0x0  nop
    ctx->pc = 0x1611dcu;
    // NOP
label_1611e0:
    // 0x1611e0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1611E0u;
    {
        const bool branch_taken_0x1611e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1611E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1611E0u;
            // 0x1611e4: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1611e0) {
            ctx->pc = 0x1611F8u;
            goto label_1611f8;
        }
    }
    ctx->pc = 0x1611E8u;
    // 0x1611e8: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1611E8u;
    SET_GPR_U32(ctx, 31, 0x1611F0u);
    ctx->pc = 0x1611ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1611E8u;
            // 0x1611ec: 0x2484fac0  addiu       $a0, $a0, -0x540 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965952));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1611F0u; }
        if (ctx->pc != 0x1611F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1611F0u; }
        if (ctx->pc != 0x1611F0u) { return; }
    }
    ctx->pc = 0x1611F0u;
label_1611f0:
    // 0x1611f0: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1611F0u;
    {
        const bool branch_taken_0x1611f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1611F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1611F0u;
            // 0x1611f4: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1611f0) {
            ctx->pc = 0x161228u;
            goto label_161228;
        }
    }
    ctx->pc = 0x1611F8u;
label_1611f8:
    // 0x1611f8: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x1611F8u;
    SET_GPR_U32(ctx, 31, 0x161200u);
    ctx->pc = 0x1611FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1611F8u;
            // 0x1611fc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161200u; }
        if (ctx->pc != 0x161200u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161200u; }
        if (ctx->pc != 0x161200u) { return; }
    }
    ctx->pc = 0x161200u;
label_161200:
    // 0x161200: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x161200u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161204: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x161204u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161208: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x161208u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16120c: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x16120Cu;
    SET_GPR_U32(ctx, 31, 0x161214u);
    ctx->pc = 0x161210u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16120Cu;
            // 0x161210: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161214u; }
        if (ctx->pc != 0x161214u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161214u; }
        if (ctx->pc != 0x161214u) { return; }
    }
    ctx->pc = 0x161214u;
label_161214:
    // 0x161214: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x161214u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161218: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161218u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16121c: 0xc05ed4c  jal         func_17B530
    ctx->pc = 0x16121Cu;
    SET_GPR_U32(ctx, 31, 0x161224u);
    ctx->pc = 0x161220u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16121Cu;
            // 0x161220: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B530u;
    if (runtime->hasFunction(0x17B530u)) {
        auto targetFn = runtime->lookupFunction(0x17B530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161224u; }
        if (ctx->pc != 0x161224u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017B530_0x17b530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161224u; }
        if (ctx->pc != 0x161224u) { return; }
    }
    ctx->pc = 0x161224u;
label_161224:
    // 0x161224: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x161224u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_161228:
    // 0x161228: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x161228u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x16122c: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x16122cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x161230: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x161230u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x161234: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x161234u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x161238: 0x3e00008  jr          $ra
    ctx->pc = 0x161238u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16123Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161238u;
            // 0x16123c: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1611C0u: goto label_1611c0;
            case 0x1611D4u: goto label_1611d4;
            case 0x1611E0u: goto label_1611e0;
            case 0x1611F0u: goto label_1611f0;
            case 0x1611F8u: goto label_1611f8;
            case 0x161200u: goto label_161200;
            case 0x161214u: goto label_161214;
            case 0x161224u: goto label_161224;
            case 0x161228u: goto label_161228;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161240u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
