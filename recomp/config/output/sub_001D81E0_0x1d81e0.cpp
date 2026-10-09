#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D81E0
// Address: 0x1d81e0 - 0x1d8290
void sub_001D81E0_0x1d81e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D81E0_0x1d81e0");
#endif

    switch (ctx->pc) {
        case 0x1d820cu: goto label_1d820c;
        case 0x1d8234u: goto label_1d8234;
        case 0x1d8268u: goto label_1d8268;
        default: break;
    }

    ctx->pc = 0x1d81e0u;

    // 0x1d81e0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d81e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d81e4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d81e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d81e8: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d81e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d81ec: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d81ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d81f0: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1d81f0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d81f4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d81f4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d81f8: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1d81f8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d81fc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d81fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d8200: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x1d8200u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8204: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D8204u;
    SET_GPR_U32(ctx, 31, 0x1D820Cu);
    ctx->pc = 0x1D8208u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8204u;
            // 0x1d8208: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D820Cu; }
        if (ctx->pc != 0x1D820Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D820Cu; }
        if (ctx->pc != 0x1D820Cu) { return; }
    }
    ctx->pc = 0x1D820Cu;
label_1d820c:
    // 0x1d820c: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d820cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d8210: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d8210u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d8214: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d8214u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d8218: 0x24040016  addiu       $a0, $zero, 0x16
    ctx->pc = 0x1d8218u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x1d821c: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d821cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d8220: 0x24060022  addiu       $a2, $zero, 0x22
    ctx->pc = 0x1d8220u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x1d8224: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d8224u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d8228: 0x2408002c  addiu       $t0, $zero, 0x2C
    ctx->pc = 0x1d8228u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 44));
    // 0x1d822c: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D822Cu;
    SET_GPR_U32(ctx, 31, 0x1D8234u);
    ctx->pc = 0x1D8230u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D822Cu;
            // 0x1d8230: 0xa430729c  sh          $s0, 0x729C($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 29340), (uint16_t)GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8234u; }
        if (ctx->pc != 0x1D8234u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8234u; }
        if (ctx->pc != 0x1D8234u) { return; }
    }
    ctx->pc = 0x1D8234u;
label_1d8234:
    // 0x1d8234: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d8234u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d8238: 0x84306298  lh          $s0, 0x6298($at)
    ctx->pc = 0x1d8238u;
    SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
    // 0x1d823c: 0x16000008  bnez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D823Cu;
    {
        const bool branch_taken_0x1d823c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D8240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D823Cu;
            // 0x1d8240: 0x3c030034  lui         $v1, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d823c) {
            ctx->pc = 0x1D8260u;
            goto label_1d8260;
        }
    }
    ctx->pc = 0x1D8244u;
    // 0x1d8244: 0x2463629c  addiu       $v1, $v1, 0x629C
    ctx->pc = 0x1d8244u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 25244));
    // 0x1d8248: 0x84620002  lh          $v0, 0x2($v1)
    ctx->pc = 0x1d8248u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 2)));
    // 0x1d824c: 0xa6620000  sh          $v0, 0x0($s3)
    ctx->pc = 0x1d824cu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1d8250: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x1d8250u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1d8254: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x1d8254u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1d8258: 0x94620008  lhu         $v0, 0x8($v1)
    ctx->pc = 0x1d8258u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1d825c: 0xa6220000  sh          $v0, 0x0($s1)
    ctx->pc = 0x1d825cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 2));
label_1d8260:
    // 0x1d8260: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D8260u;
    SET_GPR_U32(ctx, 31, 0x1D8268u);
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8268u; }
        if (ctx->pc != 0x1D8268u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8268u; }
        if (ctx->pc != 0x1D8268u) { return; }
    }
    ctx->pc = 0x1D8268u;
label_1d8268:
    // 0x1d8268: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d8268u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d826c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d826cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d8270: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d8270u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d8274: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d8274u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d8278: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d8278u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d827c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d827cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d8280: 0x3e00008  jr          $ra
    ctx->pc = 0x1D8280u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D8284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8280u;
            // 0x1d8284: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D820Cu: goto label_1d820c;
            case 0x1D8234u: goto label_1d8234;
            case 0x1D8260u: goto label_1d8260;
            case 0x1D8268u: goto label_1d8268;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D8288u;
    // 0x1d8288: 0x0  nop
    ctx->pc = 0x1d8288u;
    // NOP
    // 0x1d828c: 0x0  nop
    ctx->pc = 0x1d828cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
