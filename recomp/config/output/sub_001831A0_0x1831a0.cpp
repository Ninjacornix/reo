#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001831A0
// Address: 0x1831a0 - 0x183234
void sub_001831A0_0x1831a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001831A0_0x1831a0");
#endif

    switch (ctx->pc) {
        case 0x1831d8u: goto label_1831d8;
        case 0x1831e4u: goto label_1831e4;
        default: break;
    }

    ctx->pc = 0x1831a0u;

    // 0x1831a0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1831a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1831a4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1831a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1831a8: 0x3c117fff  lui         $s1, 0x7FFF
    ctx->pc = 0x1831a8u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)32767 << 16));
    // 0x1831ac: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1831acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1831b0: 0x3631ffff  ori         $s1, $s1, 0xFFFF
    ctx->pc = 0x1831b0u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)65535);
    // 0x1831b4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1831b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1831b8: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x1831b8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1831bc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1831bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1831c0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1831c0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1831c4: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x1831c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x1831c8: 0x3c138000  lui         $s3, 0x8000
    ctx->pc = 0x1831c8u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)32768 << 16));
    // 0x1831cc: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x1831ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x1831d0: 0x2414ffff  addiu       $s4, $zero, -0x1
    ctx->pc = 0x1831d0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1831d4: 0x0  nop
    ctx->pc = 0x1831d4u;
    // NOP
label_1831d8:
    // 0x1831d8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1831d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1831dc: 0xc060b02  jal         func_182C08
    ctx->pc = 0x1831DCu;
    SET_GPR_U32(ctx, 31, 0x1831E4u);
    ctx->pc = 0x1831E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1831DCu;
            // 0x1831e0: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182C08u;
    if (runtime->hasFunction(0x182C08u)) {
        auto targetFn = runtime->lookupFunction(0x182C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1831E4u; }
        if (ctx->pc != 0x1831E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182C08_0x182c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1831E4u; }
        if (ctx->pc != 0x1831E4u) { return; }
    }
    ctx->pc = 0x1831E4u;
label_1831e4:
    // 0x1831e4: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x1831e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1831e8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1831e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1831ec: 0xb32024  and         $a0, $a1, $s3
    ctx->pc = 0x1831ecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & GPR_U64(ctx, 19));
    // 0x1831f0: 0x14600008  bnez        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1831F0u;
    {
        const bool branch_taken_0x1831f0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1831F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1831F0u;
            // 0x1831f4: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1831f0) {
            ctx->pc = 0x183214u;
            goto label_183214;
        }
    }
    ctx->pc = 0x1831F8u;
    // 0x1831f8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1831f8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1831fc: 0x10b40005  beq         $a1, $s4, . + 4 + (0x5 << 2)
    ctx->pc = 0x1831FCu;
    {
        const bool branch_taken_0x1831fc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 20));
        ctx->pc = 0x183200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1831FCu;
            // 0x183200: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1831fc) {
            ctx->pc = 0x183214u;
            goto label_183214;
        }
    }
    ctx->pc = 0x183204u;
    // 0x183204: 0x1480fff4  bnez        $a0, . + 4 + (-0xC << 2)
    ctx->pc = 0x183204u;
    {
        const bool branch_taken_0x183204 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x183208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183204u;
            // 0x183208: 0xb12824  and         $a1, $a1, $s1 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183204) {
            ctx->pc = 0x1831D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1831d8;
        }
    }
    ctx->pc = 0x18320Cu;
    // 0x18320c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x18320cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x183210: 0x34429002  ori         $v0, $v0, 0x9002
    ctx->pc = 0x183210u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36866);
label_183214:
    // 0x183214: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x183214u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x183218: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x183218u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x18321c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x18321cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x183220: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x183220u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x183224: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x183224u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x183228: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x183228u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x18322c: 0x3e00008  jr          $ra
    ctx->pc = 0x18322Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x183230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18322Cu;
            // 0x183230: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1831D8u: goto label_1831d8;
            case 0x1831E4u: goto label_1831e4;
            case 0x183214u: goto label_183214;
            default: break;
        }
        return;
    }
    ctx->pc = 0x183234u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
