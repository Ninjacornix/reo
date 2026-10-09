#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172908
// Address: 0x172908 - 0x1729b0
void sub_00172908_0x172908(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172908_0x172908");
#endif

    switch (ctx->pc) {
        case 0x172938u: goto label_172938;
        case 0x17294cu: goto label_17294c;
        case 0x172970u: goto label_172970;
        case 0x172984u: goto label_172984;
        default: break;
    }

    ctx->pc = 0x172908u;

    // 0x172908: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x172908u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17290c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17290cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x172910: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x172910u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x172914: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x172914u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x172918: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x172918u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17291c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x17291cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x172920: 0x263009a0  addiu       $s0, $s1, 0x9A0
    ctx->pc = 0x172920u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 2464));
    // 0x172924: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x172924u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x172928: 0x5443000b  bnel        $v0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x172928u;
    {
        const bool branch_taken_0x172928 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x172928) {
            ctx->pc = 0x17292Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172928u;
            // 0x17292c: 0x8e060018  lw          $a2, 0x18($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172958u;
            goto label_172958;
        }
    }
    ctx->pc = 0x172930u;
    // 0x172930: 0xc059d52  jal         func_167548
    ctx->pc = 0x172930u;
    SET_GPR_U32(ctx, 31, 0x172938u);
    ctx->pc = 0x172934u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172930u;
            // 0x172934: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167548u;
    if (runtime->hasFunction(0x167548u)) {
        auto targetFn = runtime->lookupFunction(0x167548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172938u; }
        if (ctx->pc != 0x172938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167548_0x167548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172938u; }
        if (ctx->pc != 0x172938u) { return; }
    }
    ctx->pc = 0x172938u;
label_172938:
    // 0x172938: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x172938u;
    {
        const bool branch_taken_0x172938 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x172938) {
            ctx->pc = 0x17293Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172938u;
            // 0x17293c: 0x8e060018  lw          $a2, 0x18($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172958u;
            goto label_172958;
        }
    }
    ctx->pc = 0x172940u;
    // 0x172940: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x172940u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172944: 0xc059d4a  jal         func_167528
    ctx->pc = 0x172944u;
    SET_GPR_U32(ctx, 31, 0x17294Cu);
    ctx->pc = 0x172948u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172944u;
            // 0x172948: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167528u;
    if (runtime->hasFunction(0x167528u)) {
        auto targetFn = runtime->lookupFunction(0x167528u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17294Cu; }
        if (ctx->pc != 0x17294Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167528_0x167528(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17294Cu; }
        if (ctx->pc != 0x17294Cu) { return; }
    }
    ctx->pc = 0x17294Cu;
label_17294c:
    // 0x17294c: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x17294Cu;
    {
        const bool branch_taken_0x17294c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x17294c) {
            ctx->pc = 0x172950u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17294Cu;
            // 0x172950: 0xae000014  sw          $zero, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172954u;
            goto label_172954;
        }
    }
    ctx->pc = 0x172954u;
label_172954:
    // 0x172954: 0x8e060018  lw          $a2, 0x18($s0)
    ctx->pc = 0x172954u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
label_172958:
    // 0x172958: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x172958u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17295c: 0x54c2000e  bnel        $a2, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x17295Cu;
    {
        const bool branch_taken_0x17295c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        if (branch_taken_0x17295c) {
            ctx->pc = 0x172960u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17295Cu;
            // 0x172960: 0x8e050014  lw          $a1, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172998u;
            goto label_172998;
        }
    }
    ctx->pc = 0x172964u;
    // 0x172964: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x172964u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172968: 0xc059d52  jal         func_167548
    ctx->pc = 0x172968u;
    SET_GPR_U32(ctx, 31, 0x172970u);
    ctx->pc = 0x17296Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172968u;
            // 0x17296c: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167548u;
    if (runtime->hasFunction(0x167548u)) {
        auto targetFn = runtime->lookupFunction(0x167548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172970u; }
        if (ctx->pc != 0x172970u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167548_0x167548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172970u; }
        if (ctx->pc != 0x172970u) { return; }
    }
    ctx->pc = 0x172970u;
label_172970:
    // 0x172970: 0x54400008  bnel        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x172970u;
    {
        const bool branch_taken_0x172970 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x172970) {
            ctx->pc = 0x172974u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172970u;
            // 0x172974: 0x8e060018  lw          $a2, 0x18($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172994u;
            goto label_172994;
        }
    }
    ctx->pc = 0x172978u;
    // 0x172978: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x172978u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17297c: 0xc059d4a  jal         func_167528
    ctx->pc = 0x17297Cu;
    SET_GPR_U32(ctx, 31, 0x172984u);
    ctx->pc = 0x172980u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17297Cu;
            // 0x172980: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167528u;
    if (runtime->hasFunction(0x167528u)) {
        auto targetFn = runtime->lookupFunction(0x167528u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172984u; }
        if (ctx->pc != 0x172984u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167528_0x167528(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172984u; }
        if (ctx->pc != 0x172984u) { return; }
    }
    ctx->pc = 0x172984u;
label_172984:
    // 0x172984: 0x54400003  bnel        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x172984u;
    {
        const bool branch_taken_0x172984 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x172984) {
            ctx->pc = 0x172988u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172984u;
            // 0x172988: 0x8e060018  lw          $a2, 0x18($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172994u;
            goto label_172994;
        }
    }
    ctx->pc = 0x17298Cu;
    // 0x17298c: 0xae000018  sw          $zero, 0x18($s0)
    ctx->pc = 0x17298cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x172990: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x172990u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_172994:
    // 0x172994: 0x8e050014  lw          $a1, 0x14($s0)
    ctx->pc = 0x172994u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
label_172998:
    // 0x172998: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x172998u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17299c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17299cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1729a0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1729a0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1729a4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1729a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1729a8: 0x805d212  j           func_174848
    ctx->pc = 0x1729A8u;
    ctx->pc = 0x1729ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1729A8u;
            // 0x1729ac: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x174848u;
    if (runtime->hasFunction(0x174848u)) {
        auto targetFn = runtime->lookupFunction(0x174848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00174848_0x174848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1729B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
