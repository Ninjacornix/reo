#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016A138
// Address: 0x16a138 - 0x16a1bc
void sub_0016A138_0x16a138(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016A138_0x16a138");
#endif

    switch (ctx->pc) {
        case 0x16a168u: goto label_16a168;
        case 0x16a188u: goto label_16a188;
        case 0x16a1a4u: goto label_16a1a4;
        default: break;
    }

    ctx->pc = 0x16a138u;

    // 0x16a138: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16a138u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16a13c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16a13cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16a140: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16a140u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16a144: 0x805a854  j           func_16A150
    ctx->pc = 0x16A144u;
    ctx->pc = 0x16A148u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A144u;
            // 0x16a148: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16A150u;
    goto label_16a150;
    ctx->pc = 0x16A14Cu;
    // 0x16a14c: 0x0  nop
    ctx->pc = 0x16a14cu;
    // NOP
label_16a150:
    // 0x16a150: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16a150u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16a154: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16a154u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16a158: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16a158u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16a15c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x16a15cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x16a160: 0xc05ac10  jal         func_16B040
    ctx->pc = 0x16A160u;
    SET_GPR_U32(ctx, 31, 0x16A168u);
    ctx->pc = 0x16A164u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A160u;
            // 0x16a164: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16B040u;
    if (runtime->hasFunction(0x16B040u)) {
        auto targetFn = runtime->lookupFunction(0x16B040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A168u; }
        if (ctx->pc != 0x16A168u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016B040_0x16b040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A168u; }
        if (ctx->pc != 0x16A168u) { return; }
    }
    ctx->pc = 0x16A168u;
label_16a168:
    // 0x16a168: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x16a168u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16a16c: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x16A16Cu;
    {
        const bool branch_taken_0x16a16c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x16A170u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A16Cu;
            // 0x16a170: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a16c) {
            ctx->pc = 0x16A180u;
            goto label_16a180;
        }
    }
    ctx->pc = 0x16A174u;
    // 0x16a174: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x16A174u;
    {
        const bool branch_taken_0x16a174 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A174u;
            // 0x16a178: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a174) {
            ctx->pc = 0x16A1A8u;
            goto label_16a1a8;
        }
    }
    ctx->pc = 0x16A17Cu;
    // 0x16a17c: 0x0  nop
    ctx->pc = 0x16a17cu;
    // NOP
label_16a180:
    // 0x16a180: 0xc05a870  jal         func_16A1C0
    ctx->pc = 0x16A180u;
    SET_GPR_U32(ctx, 31, 0x16A188u);
    ctx->pc = 0x16A1C0u;
    if (runtime->hasFunction(0x16A1C0u)) {
        auto targetFn = runtime->lookupFunction(0x16A1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A188u; }
        if (ctx->pc != 0x16A188u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016A1C0_0x16a1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A188u; }
        if (ctx->pc != 0x16A188u) { return; }
    }
    ctx->pc = 0x16A188u;
label_16a188:
    // 0x16a188: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x16a188u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x16a18c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x16a18cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a190: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x16a190u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x16a194: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x16A194u;
    {
        const bool branch_taken_0x16a194 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x16A198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A194u;
            // 0x16a198: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a194) {
            ctx->pc = 0x16A1A4u;
            goto label_16a1a4;
        }
    }
    ctx->pc = 0x16A19Cu;
    // 0x16a19c: 0xc05ac9a  jal         func_16B268
    ctx->pc = 0x16A19Cu;
    SET_GPR_U32(ctx, 31, 0x16A1A4u);
    ctx->pc = 0x16B268u;
    if (runtime->hasFunction(0x16B268u)) {
        auto targetFn = runtime->lookupFunction(0x16B268u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A1A4u; }
        if (ctx->pc != 0x16A1A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016B268_0x16b268(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A1A4u; }
        if (ctx->pc != 0x16A1A4u) { return; }
    }
    ctx->pc = 0x16A1A4u;
label_16a1a4:
    // 0x16a1a4: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x16a1a4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_16a1a8:
    // 0x16a1a8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16a1a8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16a1ac: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16a1acu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16a1b0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16a1b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16a1b4: 0x3e00008  jr          $ra
    ctx->pc = 0x16A1B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16A1B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A1B4u;
            // 0x16a1b8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A150u: goto label_16a150;
            case 0x16A168u: goto label_16a168;
            case 0x16A180u: goto label_16a180;
            case 0x16A188u: goto label_16a188;
            case 0x16A1A4u: goto label_16a1a4;
            case 0x16A1A8u: goto label_16a1a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16A1BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
