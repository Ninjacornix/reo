#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016E930
// Address: 0x16e930 - 0x16e9b8
void sub_0016E930_0x16e930(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016E930_0x16e930");
#endif

    switch (ctx->pc) {
        case 0x16e95cu: goto label_16e95c;
        case 0x16e990u: goto label_16e990;
        default: break;
    }

    ctx->pc = 0x16e930u;

    // 0x16e930: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16e930u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16e934: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x16e934u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x16e938: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16e938u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16e93c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16e93cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e940: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16e940u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16e944: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x16e944u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e948: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x16e948u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x16e94c: 0x14a30015  bne         $a1, $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x16E94Cu;
    {
        const bool branch_taken_0x16e94c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x16E950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E94Cu;
            // 0x16e950: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e94c) {
            ctx->pc = 0x16E9A4u;
            goto label_16e9a4;
        }
    }
    ctx->pc = 0x16E954u;
    // 0x16e954: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16E954u;
    SET_GPR_U32(ctx, 31, 0x16E95Cu);
    ctx->pc = 0x16E958u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E954u;
            // 0x16e958: 0x24050007  addiu       $a1, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E95Cu; }
        if (ctx->pc != 0x16E95Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E95Cu; }
        if (ctx->pc != 0x16E95Cu) { return; }
    }
    ctx->pc = 0x16E95Cu;
label_16e95c:
    // 0x16e95c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x16E95Cu;
    {
        const bool branch_taken_0x16e95c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16E960u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E95Cu;
            // 0x16e960: 0x2603090c  addiu       $v1, $s0, 0x90C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 2316));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e95c) {
            ctx->pc = 0x16E970u;
            goto label_16e970;
        }
    }
    ctx->pc = 0x16E964u;
    // 0x16e964: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x16E964u;
    {
        const bool branch_taken_0x16e964 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16E968u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E964u;
            // 0x16e968: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e964) {
            ctx->pc = 0x16E9A4u;
            goto label_16e9a4;
        }
    }
    ctx->pc = 0x16E96Cu;
    // 0x16e96c: 0x0  nop
    ctx->pc = 0x16e96cu;
    // NOP
label_16e970:
    // 0x16e970: 0x8c660008  lw          $a2, 0x8($v1)
    ctx->pc = 0x16e970u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x16e974: 0x2610094c  addiu       $s0, $s0, 0x94C
    ctx->pc = 0x16e974u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 2380));
    // 0x16e978: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x16e978u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x16e97c: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x16e97cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x16e980: 0xc20018  mult        $zero, $a2, $v0
    ctx->pc = 0x16e980u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x16e984: 0x3012  mflo        $a2
    ctx->pc = 0x16e984u;
    SET_GPR_U64(ctx, 6, ctx->lo);
    // 0x16e988: 0xc05625a  jal         func_158968
    ctx->pc = 0x16E988u;
    SET_GPR_U32(ctx, 31, 0x16E990u);
    ctx->pc = 0x16E98Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E988u;
            // 0x16e98c: 0x8e240000  lw          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158968u;
    if (runtime->hasFunction(0x158968u)) {
        auto targetFn = runtime->lookupFunction(0x158968u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E990u; }
        if (ctx->pc != 0x16E990u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158968_0x158968(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E990u; }
        if (ctx->pc != 0x16E990u) { return; }
    }
    ctx->pc = 0x16E990u;
label_16e990:
    // 0x16e990: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x16E990u;
    {
        const bool branch_taken_0x16e990 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16e990) {
            ctx->pc = 0x16E994u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16E990u;
            // 0x16e994: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16E9A8u;
            goto label_16e9a8;
        }
    }
    ctx->pc = 0x16E998u;
    // 0x16e998: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x16e998u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x16e99c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x16e99cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x16e9a0: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x16e9a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
label_16e9a4:
    // 0x16e9a4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16e9a4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_16e9a8:
    // 0x16e9a8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16e9a8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16e9ac: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16e9acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16e9b0: 0x3e00008  jr          $ra
    ctx->pc = 0x16E9B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16E9B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E9B0u;
            // 0x16e9b4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16E95Cu: goto label_16e95c;
            case 0x16E970u: goto label_16e970;
            case 0x16E990u: goto label_16e990;
            case 0x16E9A4u: goto label_16e9a4;
            case 0x16E9A8u: goto label_16e9a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16E9B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
