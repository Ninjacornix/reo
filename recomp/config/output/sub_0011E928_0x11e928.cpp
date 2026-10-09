#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011E928
// Address: 0x11e928 - 0x11e9c8
void sub_0011E928_0x11e928(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011E928_0x11e928");
#endif

    switch (ctx->pc) {
        case 0x11e990u: goto label_11e990;
        default: break;
    }

    ctx->pc = 0x11e928u;

    // 0x11e928: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11e928u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11e92c: 0x41282  srl         $v0, $a0, 10
    ctx->pc = 0x11e92cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 10));
    // 0x11e930: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11e930u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11e934: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11e934u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11e938: 0x28180  sll         $s0, $v0, 6
    ctx->pc = 0x11e938u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x11e93c: 0x4800005  bltz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11E93Cu;
    {
        const bool branch_taken_0x11e93c = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x11E940u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E93Cu;
            // 0x11e940: 0xffb10010  sd          $s1, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e93c) {
            ctx->pc = 0x11E954u;
            goto label_11e954;
        }
    }
    ctx->pc = 0x11E944u;
    // 0x11e944: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x11e944u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11e948: 0x308203ff  andi        $v0, $a0, 0x3FF
    ctx->pc = 0x11e948u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1023);
    // 0x11e94c: 0x50430004  beql        $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x11E94Cu;
    {
        const bool branch_taken_0x11e94c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x11e94c) {
            ctx->pc = 0x11E950u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11E94Cu;
            // 0x11e950: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11E960u;
            goto label_11e960;
        }
    }
    ctx->pc = 0x11E954u;
label_11e954:
    // 0x11e954: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11e954u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11e958: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x11E958u;
    {
        const bool branch_taken_0x11e958 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E95Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E958u;
            // 0x11e95c: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e958) {
            ctx->pc = 0x11E9B4u;
            goto label_11e9b4;
        }
    }
    ctx->pc = 0x11E960u;
label_11e960:
    // 0x11e960: 0x2451b3e8  addiu       $s1, $v0, -0x4C18
    ctx->pc = 0x11e960u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294947816));
    // 0x11e964: 0x8e23001c  lw          $v1, 0x1C($s1)
    ctx->pc = 0x11e964u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x11e968: 0x54640004  bnel        $v1, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11E968u;
    {
        const bool branch_taken_0x11e968 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x11e968) {
            ctx->pc = 0x11E96Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11E968u;
            // 0x11e96c: 0x8e02000c  lw          $v0, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11E97Cu;
            goto label_11e97c;
        }
    }
    ctx->pc = 0x11E970u;
    // 0x11e970: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11e970u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11e974: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x11E974u;
    {
        const bool branch_taken_0x11e974 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E974u;
            // 0x11e978: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e974) {
            ctx->pc = 0x11E9B4u;
            goto label_11e9b4;
        }
    }
    ctx->pc = 0x11E97Cu;
label_11e97c:
    // 0x11e97c: 0x30420002  andi        $v0, $v0, 0x2
    ctx->pc = 0x11e97cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x11e980: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11E980u;
    {
        const bool branch_taken_0x11e980 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11e980) {
            ctx->pc = 0x11E990u;
            goto label_11e990;
        }
    }
    ctx->pc = 0x11E988u;
    // 0x11e988: 0xc047932  jal         func_11E4C8
    ctx->pc = 0x11E988u;
    SET_GPR_U32(ctx, 31, 0x11E990u);
    ctx->pc = 0x11E98Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E988u;
            // 0x11e98c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11E4C8u;
    if (runtime->hasFunction(0x11E4C8u)) {
        auto targetFn = runtime->lookupFunction(0x11E4C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E990u; }
        if (ctx->pc != 0x11E990u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E4C8_0x11e4c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E990u; }
        if (ctx->pc != 0x11E990u) { return; }
    }
    ctx->pc = 0x11E990u;
label_11e990:
    // 0x11e990: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x11e990u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x11e994: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11e994u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e998: 0xae00000c  sw          $zero, 0xC($s0)
    ctx->pc = 0x11e998u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x11e99c: 0x8e240014  lw          $a0, 0x14($s1)
    ctx->pc = 0x11e99cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x11e9a0: 0x8e230010  lw          $v1, 0x10($s1)
    ctx->pc = 0x11e9a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x11e9a4: 0xae040000  sw          $a0, 0x0($s0)
    ctx->pc = 0x11e9a4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 4));
    // 0x11e9a8: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x11e9a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x11e9ac: 0xae300014  sw          $s0, 0x14($s1)
    ctx->pc = 0x11e9acu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 16));
    // 0x11e9b0: 0xae230010  sw          $v1, 0x10($s1)
    ctx->pc = 0x11e9b0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 3));
label_11e9b4:
    // 0x11e9b4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11e9b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11e9b8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11e9b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11e9bc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11e9bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11e9c0: 0x3e00008  jr          $ra
    ctx->pc = 0x11E9C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E9C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E9C0u;
            // 0x11e9c4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E954u: goto label_11e954;
            case 0x11E960u: goto label_11e960;
            case 0x11E97Cu: goto label_11e97c;
            case 0x11E990u: goto label_11e990;
            case 0x11E9B4u: goto label_11e9b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E9C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
