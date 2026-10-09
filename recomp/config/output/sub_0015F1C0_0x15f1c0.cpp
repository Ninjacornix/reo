#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F1C0
// Address: 0x15f1c0 - 0x15f26c
void sub_0015F1C0_0x15f1c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F1C0_0x15f1c0");
#endif

    switch (ctx->pc) {
        case 0x15f1e4u: goto label_15f1e4;
        case 0x15f218u: goto label_15f218;
        case 0x15f22cu: goto label_15f22c;
        case 0x15f238u: goto label_15f238;
        case 0x15f250u: goto label_15f250;
        default: break;
    }

    ctx->pc = 0x15f1c0u;

    // 0x15f1c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15f1c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15f1c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f1c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f1c8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15f1c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f1cc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15f1ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15f1d0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x15f1d0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f1d4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15f1d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15f1d8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x15f1d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x15f1dc: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15F1DCu;
    SET_GPR_U32(ctx, 31, 0x15F1E4u);
    ctx->pc = 0x15F1E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F1DCu;
            // 0x15f1e0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F1E4u; }
        if (ctx->pc != 0x15F1E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F1E4u; }
        if (ctx->pc != 0x15F1E4u) { return; }
    }
    ctx->pc = 0x15F1E4u;
label_15f1e4:
    // 0x15f1e4: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x15F1E4u;
    {
        const bool branch_taken_0x15f1e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15F1E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F1E4u;
            // 0x15f1e8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f1e4) {
            ctx->pc = 0x15F210u;
            goto label_15f210;
        }
    }
    ctx->pc = 0x15F1ECu;
    // 0x15f1ec: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15f1ecu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15f1f0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f1f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f1f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f1f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f1f8: 0x2484f120  addiu       $a0, $a0, -0xEE0
    ctx->pc = 0x15f1f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963488));
    // 0x15f1fc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15f1fcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f200: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15f200u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15f204: 0x8058dd4  j           func_163750
    ctx->pc = 0x15F204u;
    ctx->pc = 0x15F208u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F204u;
            // 0x15f208: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F20Cu;
    // 0x15f20c: 0x0  nop
    ctx->pc = 0x15f20cu;
    // NOP
label_15f210:
    // 0x15f210: 0xc057cbc  jal         func_15F2F0
    ctx->pc = 0x15F210u;
    SET_GPR_U32(ctx, 31, 0x15F218u);
    ctx->pc = 0x15F2F0u;
    if (runtime->hasFunction(0x15F2F0u)) {
        auto targetFn = runtime->lookupFunction(0x15F2F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F218u; }
        if (ctx->pc != 0x15F218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F2F0_0x15f2f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F218u; }
        if (ctx->pc != 0x15F218u) { return; }
    }
    ctx->pc = 0x15F218u;
label_15f218:
    // 0x15f218: 0x8e04014c  lw          $a0, 0x14C($s0)
    ctx->pc = 0x15f218u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 332)));
    // 0x15f21c: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x15f21cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x15f220: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x15f220u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x15f224: 0x40f809  jalr        $v0
    ctx->pc = 0x15F224u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15F22Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x15F22Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F1E4u: goto label_15f1e4;
            case 0x15F210u: goto label_15f210;
            case 0x15F218u: goto label_15f218;
            case 0x15F22Cu: goto label_15f22c;
            case 0x15F238u: goto label_15f238;
            case 0x15F250u: goto label_15f250;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15F22Cu; }
            if (ctx->pc != 0x15F22Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15F22Cu;
label_15f22c:
    // 0x15f22c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15f22cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f230: 0xc04fcd8  jal         func_13F360
    ctx->pc = 0x15F230u;
    SET_GPR_U32(ctx, 31, 0x15F238u);
    ctx->pc = 0x15F234u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F230u;
            // 0x15f234: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F360u;
    if (runtime->hasFunction(0x13F360u)) {
        auto targetFn = runtime->lookupFunction(0x13F360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F238u; }
        if (ctx->pc != 0x15F238u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F360_0x13f360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F238u; }
        if (ctx->pc != 0x15F238u) { return; }
    }
    ctx->pc = 0x15F238u;
label_15f238:
    // 0x15f238: 0xae110150  sw          $s1, 0x150($s0)
    ctx->pc = 0x15f238u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 336), GPR_U32(ctx, 17));
    // 0x15f23c: 0xae020128  sw          $v0, 0x128($s0)
    ctx->pc = 0x15f23cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 296), GPR_U32(ctx, 2));
    // 0x15f240: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f240u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f244: 0xae120154  sw          $s2, 0x154($s0)
    ctx->pc = 0x15f244u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 340), GPR_U32(ctx, 18));
    // 0x15f248: 0xc057bee  jal         func_15EFB8
    ctx->pc = 0x15F248u;
    SET_GPR_U32(ctx, 31, 0x15F250u);
    ctx->pc = 0x15F24Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F248u;
            // 0x15f24c: 0xae02014c  sw          $v0, 0x14C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 332), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15EFB8u;
    if (runtime->hasFunction(0x15EFB8u)) {
        auto targetFn = runtime->lookupFunction(0x15EFB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F250u; }
        if (ctx->pc != 0x15F250u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EFB8_0x15efb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F250u; }
        if (ctx->pc != 0x15F250u) { return; }
    }
    ctx->pc = 0x15F250u;
label_15f250:
    // 0x15f250: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f250u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f254: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f254u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f258: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f258u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f25c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15f25cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f260: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15f260u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15f264: 0x8056fea  j           func_15BFA8
    ctx->pc = 0x15F264u;
    ctx->pc = 0x15F268u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F264u;
            // 0x15f268: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BFA8u;
    if (runtime->hasFunction(0x15BFA8u)) {
        auto targetFn = runtime->lookupFunction(0x15BFA8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015BFA8_0x15bfa8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F26Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
