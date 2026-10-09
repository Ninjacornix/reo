#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00158858
// Address: 0x158858 - 0x158968
void sub_00158858_0x158858(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00158858_0x158858");
#endif

    switch (ctx->pc) {
        case 0x1588a8u: goto label_1588a8;
        case 0x158920u: goto label_158920;
        default: break;
    }

    ctx->pc = 0x158858u;

    // 0x158858: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x158858u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x15885c: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x15885cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158860: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x158860u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x158864: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x158864u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158868: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x158868u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15886c: 0x2069021  addu        $s2, $s0, $a2
    ctx->pc = 0x15886cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 6)));
    // 0x158870: 0x212102b  sltu        $v0, $s0, $s2
    ctx->pc = 0x158870u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
    // 0x158874: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x158874u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x158878: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x158878u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x15887c: 0xe0a82d  daddu       $s5, $a3, $zero
    ctx->pc = 0x15887cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158880: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x158880u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x158884: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x158884u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158888: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x158888u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x15888c: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x15888cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x158890: 0x1040002a  beqz        $v0, . + 4 + (0x2A << 2)
    ctx->pc = 0x158890u;
    {
        const bool branch_taken_0x158890 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x158894u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158890u;
            // 0x158894: 0xffbf0038  sd          $ra, 0x38($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158890) {
            ctx->pc = 0x15893Cu;
            goto label_15893c;
        }
    }
    ctx->pc = 0x158898u;
    // 0x158898: 0x24140001  addiu       $s4, $zero, 0x1
    ctx->pc = 0x158898u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15889c: 0x24130002  addiu       $s3, $zero, 0x2
    ctx->pc = 0x15889cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1588a0: 0x24160003  addiu       $s6, $zero, 0x3
    ctx->pc = 0x1588a0u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1588a4: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x1588a4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
label_1588a8:
    // 0x1588a8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1588a8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1588ac: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1588acu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1588b0: 0x1074000d  beq         $v1, $s4, . + 4 + (0xD << 2)
    ctx->pc = 0x1588B0u;
    {
        const bool branch_taken_0x1588b0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 20));
        ctx->pc = 0x1588B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1588B0u;
            // 0x1588b4: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1588b0) {
            ctx->pc = 0x1588E8u;
            goto label_1588e8;
        }
    }
    ctx->pc = 0x1588B8u;
    // 0x1588b8: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1588B8u;
    {
        const bool branch_taken_0x1588b8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1588b8) {
            ctx->pc = 0x1588D8u;
            goto label_1588d8;
        }
    }
    ctx->pc = 0x1588C0u;
    // 0x1588c0: 0x1073000d  beq         $v1, $s3, . + 4 + (0xD << 2)
    ctx->pc = 0x1588C0u;
    {
        const bool branch_taken_0x1588c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 19));
        if (branch_taken_0x1588c0) {
            ctx->pc = 0x1588F8u;
            goto label_1588f8;
        }
    }
    ctx->pc = 0x1588C8u;
    // 0x1588c8: 0x10760013  beq         $v1, $s6, . + 4 + (0x13 << 2)
    ctx->pc = 0x1588C8u;
    {
        const bool branch_taken_0x1588c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 22));
        if (branch_taken_0x1588c8) {
            ctx->pc = 0x158918u;
            goto label_158918;
        }
    }
    ctx->pc = 0x1588D0u;
    // 0x1588d0: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1588D0u;
    {
        const bool branch_taken_0x1588d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1588D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1588D0u;
            // 0x1588d4: 0x212102b  sltu        $v0, $s0, $s2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1588d0) {
            ctx->pc = 0x158934u;
            goto label_158934;
        }
    }
    ctx->pc = 0x1588D8u;
label_1588d8:
    // 0x1588d8: 0x50400015  beql        $v0, $zero, . + 4 + (0x15 << 2)
    ctx->pc = 0x1588D8u;
    {
        const bool branch_taken_0x1588d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1588d8) {
            ctx->pc = 0x1588DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1588D8u;
            // 0x1588dc: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x158930u;
            goto label_158930;
        }
    }
    ctx->pc = 0x1588E0u;
    // 0x1588e0: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1588E0u;
    {
        const bool branch_taken_0x1588e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1588E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1588E0u;
            // 0x1588e4: 0x212102b  sltu        $v0, $s0, $s2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1588e0) {
            ctx->pc = 0x158934u;
            goto label_158934;
        }
    }
    ctx->pc = 0x1588E8u;
label_1588e8:
    // 0x1588e8: 0x260182d  daddu       $v1, $s3, $zero
    ctx->pc = 0x1588e8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1588ec: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1588ECu;
    {
        const bool branch_taken_0x1588ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1588F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1588ECu;
            // 0x1588f0: 0x2180b  movn        $v1, $zero, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1588ec) {
            ctx->pc = 0x158930u;
            goto label_158930;
        }
    }
    ctx->pc = 0x1588F4u;
    // 0x1588f4: 0x0  nop
    ctx->pc = 0x1588f4u;
    // NOP
label_1588f8:
    // 0x1588f8: 0x14540003  bne         $v0, $s4, . + 4 + (0x3 << 2)
    ctx->pc = 0x1588F8u;
    {
        const bool branch_taken_0x1588f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 20));
        if (branch_taken_0x1588f8) {
            ctx->pc = 0x158908u;
            goto label_158908;
        }
    }
    ctx->pc = 0x158900u;
    // 0x158900: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x158900u;
    {
        const bool branch_taken_0x158900 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x158904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158900u;
            // 0x158904: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158900) {
            ctx->pc = 0x158930u;
            goto label_158930;
        }
    }
    ctx->pc = 0x158908u;
label_158908:
    // 0x158908: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x158908u;
    {
        const bool branch_taken_0x158908 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15890Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158908u;
            // 0x15890c: 0x212102b  sltu        $v0, $s0, $s2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x158908) {
            ctx->pc = 0x158934u;
            goto label_158934;
        }
    }
    ctx->pc = 0x158910u;
    // 0x158910: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x158910u;
    {
        const bool branch_taken_0x158910 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x158914u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158910u;
            // 0x158914: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158910) {
            ctx->pc = 0x158934u;
            goto label_158934;
        }
    }
    ctx->pc = 0x158918u;
label_158918:
    // 0x158918: 0xc05616e  jal         func_1585B8
    ctx->pc = 0x158918u;
    SET_GPR_U32(ctx, 31, 0x158920u);
    ctx->pc = 0x15891Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x158918u;
            // 0x15891c: 0x2604fffc  addiu       $a0, $s0, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967292));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1585B8u;
    if (runtime->hasFunction(0x1585B8u)) {
        auto targetFn = runtime->lookupFunction(0x1585B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158920u; }
        if (ctx->pc != 0x158920u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001585B8_0x1585b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158920u; }
        if (ctx->pc != 0x158920u) { return; }
    }
    ctx->pc = 0x158920u;
label_158920:
    // 0x158920: 0x2a21824  and         $v1, $s5, $v0
    ctx->pc = 0x158920u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 21) & GPR_U64(ctx, 2));
    // 0x158924: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x158924u;
    {
        const bool branch_taken_0x158924 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x158928u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158924u;
            // 0x158928: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158924) {
            ctx->pc = 0x158940u;
            goto label_158940;
        }
    }
    ctx->pc = 0x15892Cu;
    // 0x15892c: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x15892cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_158930:
    // 0x158930: 0x212102b  sltu        $v0, $s0, $s2
    ctx->pc = 0x158930u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
label_158934:
    // 0x158934: 0x5440ffdc  bnel        $v0, $zero, . + 4 + (-0x24 << 2)
    ctx->pc = 0x158934u;
    {
        const bool branch_taken_0x158934 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x158934) {
            ctx->pc = 0x158938u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x158934u;
            // 0x158938: 0x82020000  lb          $v0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1588A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1588a8;
        }
    }
    ctx->pc = 0x15893Cu;
label_15893c:
    // 0x15893c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x15893cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_158940:
    // 0x158940: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x158940u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x158944: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x158944u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x158948: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x158948u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15894c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x15894cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x158950: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x158950u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x158954: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x158954u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x158958: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x158958u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x15895c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x15895cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x158960: 0x3e00008  jr          $ra
    ctx->pc = 0x158960u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x158964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158960u;
            // 0x158964: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1588A8u: goto label_1588a8;
            case 0x1588D8u: goto label_1588d8;
            case 0x1588E8u: goto label_1588e8;
            case 0x1588F8u: goto label_1588f8;
            case 0x158908u: goto label_158908;
            case 0x158918u: goto label_158918;
            case 0x158920u: goto label_158920;
            case 0x158930u: goto label_158930;
            case 0x158934u: goto label_158934;
            case 0x15893Cu: goto label_15893c;
            case 0x158940u: goto label_158940;
            default: break;
        }
        return;
    }
    ctx->pc = 0x158968u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
